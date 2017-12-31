#ifndef SOURCE_H   
#define SOURCE_H 

#include "Visible.hpp"
#include <iostream>

class Source : public Visible
{
	public :
	Source() : Visible() {};
	Source(Pos p, RGB c) : Visible(p,c,0) {};
	virtual void afficher(std::ostream &flux) const;

	//TO DO ces deux fonction sont juste là paske source extends visible. C'est nul
	virtual Pos calculNormale(Pos p){return p;};
	virtual Intersection* estTraverse(Segment s){Intersection* nul = NULL; s=s; return nul;};	
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