#ifndef Triangle_H   
#define Triangle_H 


#include <iostream>
#include <cstdlib>
#include <string>
#include "Intersection.hpp"



class Triangle : public Visible
{
	//3 points du triangle
	Pos position1;
	Pos position2;
	public :
	Triangle() : Visible() {}
	Triangle(Pos p, Pos p1, Pos p2, RGB c, float r) : Visible(p,c,r), position1(p1), position2(p2) {}
	virtual void afficher(std::ostream &flux) const;
	bool dansTriangle(Pos p);
	virtual Intersection* estTraverse(Segment s);
	virtual Pos calculNormale(Pos p);
};

//calcule la normale du triangle
Pos Triangle::calculNormale(Pos p)
{
	p = position;
	return p.segment(position1).produitVectoriel(position.segment(position2));
}

//retourne vrai si le point rentré en argument est dans le triangle
bool Triangle::dansTriangle(Pos p)
{

	Pos AB = position.segment(position1);

	Pos AC = position.segment(position2);

	Pos MB = p.segment(position1);
	Pos MC = p.segment(position2);
	Pos MA = p.segment(position);


	float areaABC = fabs(Pos::norm(AB)*Pos::norm(AC))/2;
	float alpha = fabs(Pos::norm(MB)*Pos::norm(MC))/(2*areaABC);
	float beta = fabs(Pos::norm(MC)*Pos::norm(MA))/(2*areaABC);
	float gamma = 1-alpha-beta;

	return (alpha<=1 && alpha >=0 && beta<=1  && beta >=0  && gamma<=1  && gamma >=0  );
}


//regarde si la droite s traverse le triangle et 
//renvoie le point d'intersection (marche avec des tests unitaires mais pas en affichage)
Intersection* Triangle::estTraverse(Segment s)
{
	
	Pos AB = position.segment(position1);
	Pos AC = position.segment(position2);
	Pos norm = AB.produitVectoriel(AC);

	//équation de plan 
	float d =(norm.getX()*(-position.getX()) + norm.getY() *(-position.getY()) + norm.getZ() * (-position.getZ()));
	if((norm.getX()*s.getVecteur().getX() + norm.getY()*s.getVecteur().getY() + norm.getZ()*s.getVecteur().getZ())!=0)
	{
		float t = -(norm.getX()*s.getOrigine().getX() + norm.getY() * s.getOrigine().getY() + norm.getZ() * s.getOrigine().getZ() + d)
					/(norm.getX()*s.getVecteur().getX() + norm.getY()*s.getVecteur().getY() + norm.getZ()*s.getVecteur().getZ());
		Pos p(s.getOrigine().getX()+s.getVecteur().getX()*t,s.getOrigine().getY()+s.getVecteur().getY()*t,s.getOrigine().getZ()+s.getVecteur().getZ()*t);
		if(dansTriangle(p))
		{

			float t = -(norm.getX()*s.getOrigine().getX() + norm.getY() * s.getOrigine().getY() + norm.getZ() * s.getOrigine().getZ() + d)
						/(norm.getX()*s.getVecteur().getX() + norm.getY()*s.getVecteur().getY() + norm.getZ()*s.getVecteur().getZ());
			Pos p(s.getOrigine().getX()+s.getVecteur().getX()*t,s.getOrigine().getY()+s.getVecteur().getY()*t,s.getOrigine().getZ()+s.getVecteur().getZ()*t);
			if(dansTriangle(p))
			{
				Intersection* i = new Intersection(p,p,color,reflexion);
				return i;
			}
			else
			{
				return NULL;
			}
			Intersection* i = new Intersection(p,calculNormale(p),color, reflexion);
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