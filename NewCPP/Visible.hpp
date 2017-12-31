#ifndef VISIBLE_H   
#define VISIBLE_H 


#include "Objets.hpp"
#include "Segment.hpp"
#include "RGB.hpp"
#include "Pos.hpp"
#include "Intersection.hpp"


class Visible 
{
	protected :
	RGB color;
	float reflexion;
	Pos position;

	public :
	Visible() {};
	Visible(Pos p, RGB c, float r): color(c), reflexion(r), position(p){};

	virtual Pos calculNormale(Pos p) = 0;
	virtual Intersection* estTraverse(Segment s) = 0;
	virtual void afficher(std::ostream &flux) const;
	virtual Segment rayReflechi(Segment rayIncident, Intersection i){return rayIncident;};
	Pos getPosition(){ return position;};
	void setPosition(Pos p){position = p;};
	void setColor(RGB color){this->color = color;}
	RGB getColor(){return color;}
	virtual float calculerAngle(Intersection i, Pos src){return 0;};
};

void Visible::afficher(std::ostream &flux) const
{
	flux << "Objet Visible de position : " << position << " et de couleur : " << color;
}

std::ostream &operator<<(std::ostream &flux, Visible const& v)
{
    v.afficher(flux) ;
    return flux;
}

#endif