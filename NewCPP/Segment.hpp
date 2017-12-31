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

void Segment::prolongeSegment(Intersection i)
{
	origine = i.getOrigine();
	Pos newvecteur;
	float scalaire = (this->vecteur.getX()*i.getNormale().getX())+(this->vecteur.getY()*i.getNormale().getY())+(this->vecteur.getZ()*i.getNormale().getZ());
	newvecteur.setX(-(2*scalaire*i.getNormale().getX())-this->vecteur.getX());
	newvecteur.setY(-(2*scalaire*i.getNormale().getY())-this->vecteur.getY());
	newvecteur.setZ(-(2*scalaire*i.getNormale().getZ())-this->vecteur.getZ());
	vecteur = newvecteur;
}

/*void Segment::prolongeSegment(Intersection inter)
{

        //on rend vecteur unitaire
        Pos directionUnitaireIncident = vecteur/vecteur.norm(vecteur);
        //cout << "incident : " << directionUnitaireIncident << "normale " << normale.getDirection() << endl;


        Pos directionReflechi = directionUnitaireIncident - 2*(directionUnitaireIncident.scal(vecteur,inter.getNormale()))*inter.getNormale();

        origine = inter.getOrigine();
        vecteur = directionReflechi;
}*/


#endif