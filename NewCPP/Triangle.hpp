#ifndef Triangle_H   
#define Triangle_H 


#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include "Intersection.hpp"



class Triangle : public Visible
{
	//3 points du triangle
	static float erreur;
	Pos position1;
	Pos position2;
	public :
	Triangle() : Visible() {}
	Triangle(Pos p, Pos p1, Pos p2, RGB c, float r) : Visible(p,c,r), position1(p1), position2(p2) {}
	virtual void afficher(std::ostream &flux) const;
	bool traversePasPlan(Pos AB, Pos AC, Segment s);
	bool dansTriangle(Pos p);
	virtual Intersection* estTraverse(Segment s);
	virtual float calculerAngle(Intersection i, Pos src);
};

float Triangle::erreur =0.1;

bool Triangle::traversePasPlan(Pos AB, Pos AC, Segment s)
{
	bool a = (AB.getX() + AC.getX() == 0) || ((AB.getY() + AC.getY() == 0) || 
		     (s.getVecteur().getX()/(AB.getX() + AC.getX())) == s.getVecteur().getY()/(AB.getY() + AC.getY()));

	bool b = (AB.getY() + AC.getY() == 0) || ((AB.getZ() + AC.getZ() == 0) || 
		     (s.getVecteur().getY()/(AB.getY() + AC.getY())) == s.getVecteur().getZ()/(AB.getZ() + AC.getZ()));

	bool c = (AB.getZ() + AC.getZ() == 0) || ((AB.getX() + AC.getX() == 0) || 
		     (s.getVecteur().getZ()/(AB.getZ() + AC.getZ())) == s.getVecteur().getX()/(AB.getX() + AC.getX()));

	return a && b && c;
}


bool Triangle::dansTriangle(Pos p)
{

	Pos AB = position.segment(position1);
	Pos AC = position.segment(position2);
	std::cout << AB << std::endl;
	std::cout << AC << std::endl;


	Pos MB = p.segment(position1);
	Pos MC = p.segment(position2);
	Pos MA = p.segment(position);

	float areaABC = abs(Pos::norm(AB)*Pos::norm(AC))/2;
	float alpha = abs(Pos::norm(MB)*Pos::norm(MC))/(2*areaABC);
	float beta = abs(Pos::norm(MC)*Pos::norm(MA))/(2*areaABC);
	float gamma = 1-alpha-beta;

	std::cout << areaABC << std::endl;
	std::cout << alpha << std::endl;
	std::cout << beta << std::endl;
	std::cout << gamma << std::endl;

	return (alpha<=1 && alpha >=0 && beta<=1 && beta >=0 && gamma<=1 && gamma >=0 );
}

Intersection* Triangle::estTraverse(Segment s)
{
	Pos AB = position.segment(position1);
	Pos AC = position.segment(position2);
	if(traversePasPlan(AB,AC,s))
	{
		std::cout << "traversePasPlan" << std::endl;
		return NULL;
	}
	else
	{
		Pos norm = AB.produitVectoriel(AC);

		//équation de plan 
		float d =(norm.getX()*(-position.getX()) + norm.getY() *(-position.getY()) + norm.getZ() * (-position.getZ()));
		if((norm.getX()*s.getVecteur().getX() + norm.getY()*s.getVecteur().getY() + norm.getZ()*s.getVecteur().getZ())!=0)
		{
			float t = -(norm.getX()*s.getOrigine().getX() + norm.getY() * s.getOrigine().getY() + norm.getZ() * s.getOrigine().getZ() + d)
						/(norm.getX()*s.getVecteur().getX() + norm.getY()*s.getVecteur().getY() + norm.getZ()*s.getVecteur().getZ());
			Pos p(s.getOrigine().getX()+s.getVecteur().getX()*t,s.getOrigine().getY()+s.getVecteur().getY()*t,s.getOrigine().getZ()+s.getVecteur().getZ()*t);
			std::cout << p << std::endl;
			if(dansTriangle(p))
			{
				Intersection* i = new Intersection(p,p,color);
				return i;
			}
			else
			{
				return NULL;
			}

		}
		else
		{
			return NULL;
		}
	}
	return NULL;
}

void Triangle::afficher(std::ostream &flux) const
{
	flux << "Objet Triangle de position ABC : " << position << position1 << position2 << " de couleur : " << color << " de reflexion : " << reflexion ;
}

std::ostream &operator<<(std::ostream &flux, Triangle const& s)
{
    s.afficher(flux) ;
    return flux;
}
#endif