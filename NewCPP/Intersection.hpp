#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Pos.hpp"
#include "RGB.hpp"


class Intersection
{

	Pos origine;
	Pos normale;
	RGB color;

	public :

	Intersection(){};
	Intersection(Pos p1, Pos p2, RGB c) : origine(p1),normale(p2), color(c){}


	Pos getOrigine(){return origine;}
	Pos getNormale(){return normale;}
	RGB getColor(){return color;}
	void setOrigine(Pos origine){this->origine = origine;}
	void setNormale(Pos normale){this->normale = normale;}
	void setColor(RGB color){this->color = color;}
	bool estEgal(Intersection p);
};


//à changer ? 
bool Intersection::estEgal(Intersection p){
	return this->origine.getX() == p.origine.getX() 
	&& this->origine.getY() == p.origine.getY() && this->origine.getZ() == p.origine.getZ(); 
}

#endif