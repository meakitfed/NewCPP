#ifndef SEGMENT_H
#define SEGMENT_H

#include "Pos.hpp"
#include "Intersection.hpp"

class Segment
{
	Pos origine;
	Pos vecteur;
	Pos posCourant;
	public :
	Segment(Pos p1, Pos p2) : origine(p1)
	{
		vecteur = p1.segment(p2);
		vecteur = vecteur/Pos::norm(vecteur);
	}
	void prolongeSegment(Intersection i);
	Pos getVecteur(){return vecteur;}
	void setVecteur(Pos s){this->vecteur=s;}
	Pos getOrigine(){return origine;}
};

#endif