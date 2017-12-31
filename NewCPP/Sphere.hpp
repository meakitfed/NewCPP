#ifndef SPHERE_H   
#define SPHERE_H 


#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include "Intersection.hpp"

class Sphere : public Visible
{
	float rayon;
	public :
	Sphere() : Visible() {}
	Sphere(Pos p, RGB c, float r, float ray) : Visible(p,c,r), rayon(ray) {}
	virtual void afficher(std::ostream &flux) const;
	virtual Intersection* estTraverse(Segment s);
	Pos calculNormale (Pos p);
};



//renvoie NULL si aucun objet de la scène est traversé par le segment(en fait une droite), 
//renvoie le point d'intersection
Intersection* Sphere::estTraverse(Segment s)
{

	float a = pow(s.getVecteur().getX(),2) + pow(s.getVecteur().getY(),2) +pow(s.getVecteur().getZ(),2);
	float b = (s.getVecteur().getX()*(s.getOrigine().getX()-position.getX()))*2 + ((s.getVecteur().getY()*(s.getOrigine().getY()-position.getY()))*2) + ((s.getVecteur().getZ()*(s.getOrigine().getZ()-position.getZ()))*2);
	float c = pow((s.getOrigine().getX()-position.getX()),2) + pow((s.getOrigine().getY()-position.getY()),2) + pow((s.getOrigine().getZ()-position.getZ()),2) - pow(rayon,2);
	
	float discri = pow(b,2) - 4.0f*a*c;	
	
	if(discri > 0)
	{
		float t1 = (- b + sqrt(discri))/ (2*a);
		float t2 = (- b - sqrt(discri))/ (2*a);
		Pos p1(s.getVecteur().getX()*t1 + s.getOrigine().getX(), s.getVecteur().getY()*t1 + s.getOrigine().getY(),s.getVecteur().getZ()*t1 + s.getOrigine().getZ());
		Pos p2(s.getVecteur().getX()*t2 + s.getOrigine().getX(), s.getVecteur().getY()*t2 + s.getOrigine().getY(),s.getVecteur().getZ()*t2 + s.getOrigine().getZ());
		if(s.getOrigine().distanceAvecPoint(p1) < s.getOrigine().distanceAvecPoint(p2))
		{
			Intersection* i = new Intersection(p1,calculNormale(p1),color, reflexion);
			return i;
		}
		else
		{
			Intersection* i = new Intersection(p2,calculNormale(p2),color, reflexion);
			return i;
		}								 
	}
	else if(discri == 0)
	{
		float t = - b / (2*a);
		Pos p(s.getVecteur().getX()*t + s.getOrigine().getX(), s.getVecteur().getY()*t + s.getOrigine().getY(),s.getVecteur().getZ()*t + s.getOrigine().getZ());
		Intersection* i = new Intersection(p,calculNormale(p),color, reflexion);

		return i;
	}
	else
	{
		return NULL;
	}	
}

void Sphere::afficher(std::ostream &flux) const
{
	flux << "Objet Sphere de position : " << position << " de couleur : " << color << " de reflexion : " << reflexion << " et de rayon : " << rayon ;
}

std::ostream &operator<<(std::ostream &flux, Sphere const& s)
{
    s.afficher(flux);
    return flux;
}


//calcule la normale de la sphere
Pos Sphere::calculNormale(Pos p)
{
	Pos normale = position.segment(p);
	normale = normale/Pos::norm(normale);
	return normale;
}

#endif