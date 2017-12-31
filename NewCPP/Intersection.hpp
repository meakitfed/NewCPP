#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Pos.hpp"
#include "RGB.hpp"


class Intersection
{
	Pos origine;
	Pos normale;
	RGB color;
	float refl;

	public :

	Intersection(){};
	Intersection(Pos p1, Pos p2, RGB c, float r) : origine(p1),normale(p2), color(c), refl(r) {};
	float getRefl(){return refl;}
	void setRefl(float r){this->refl = r;}
	Pos getOrigine(){return origine;}
	Pos getNormale(){return normale;}
	RGB getColor(){return color;}
	void setOrigine(Pos origine){this->origine = origine;}
	void setNormale(Pos normale){this->normale = normale;}
	void setColor(RGB color){this->color = color;}
};

#endif