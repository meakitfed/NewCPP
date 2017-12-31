#ifndef SOURCE_H   
#define SOURCE_H 

#include "Visible.hpp"
#include "Pos.hpp"
#include "RGB.hpp"
#include <iostream>

class Source 
{
	Pos position;
	RGB color; 
	public :
	Source() {};
	Source(Pos p, RGB c) : position(p), color(c) {};
	virtual void afficher(std::ostream &flux) const;
	Pos getPosition(){ return position;};
	void setPosition(Pos p){position = p;};
	void setColor(RGB color){this->color = color;}
	RGB getColor(){return color;}
	
};

void Source::afficher(std::ostream &flux) const
{
	flux << "Source de lumière de couleur : " << color << " et de position : " << position;
}
std::ostream &operator<<(std::ostream &flux, Source const& src)
{
    src.afficher(flux) ;
    return flux;
}

#endif