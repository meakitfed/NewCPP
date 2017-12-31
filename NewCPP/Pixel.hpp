#ifndef PIXEL_H
#define PIXEL_H

#include "RGB.hpp"
#include "Visible.hpp"
#include "Pos.hpp"
#include "Intersection.hpp"
#include "Segment.hpp"

class Pixel 
{
	private:
	Pos position;
	RGB couleur;

	public :
	Pixel() {};
	~Pixel() {};
	Pixel(Pos p, RGB c) : position(p), couleur(c) {};
	RGB getColor(){return couleur;}
	void setColor(RGB c){couleur=c;}
	Pos getPosition(){return position;}
	void setPosition(Pos p){position=p;}
	RGB drawPixel(Segment incident, std::vector<Visible*>* obj, Source src);
	RGB couleurPropre(Intersection inter, Source src, int e);
};

//calcule la couleur qui vient de l'objet en lui-même (seulement avec la source lumineuse)
RGB Pixel::couleurPropre(Intersection inter, Source src , int e)
{
	RGB couleurCalculee;
	Segment intersrc(inter.getOrigine(), src.getPosition());
	couleurCalculee = e*inter.getNormale().calculeCos(intersrc.getVecteur())*inter.getColor()*src.getColor();
	return couleurCalculee;
}

//fonction qui renvoie la couleur d'un pixel 
RGB Pixel::drawPixel(Segment incident, std::vector<Visible*>* obj, Source src){
	float distanceAvecPixel=-1;
	Intersection inter;
	//creation du segment qui part de cam vers le pixel

	//pour tout les objets visibles
	for(std::vector<Visible*>::iterator o = obj->begin() ; o != obj->end(); ++o)
	{
		Intersection* interTemp = (*o)->estTraverse(incident);

		//si intersection trouvee
		//on met à jour la distance si nécessaire
		if(interTemp != NULL)
		{
			float d = incident.getOrigine().distanceAvecPoint(interTemp->getOrigine());
			if(distanceAvecPixel > d || distanceAvecPixel==-1)
			{
				inter = *interTemp;
				distanceAvecPixel = d;
			}
		}
		delete interTemp;
	}

	int e=1;
	if(distanceAvecPixel!=-1)
	{
		RGB couleurCalculee;
		Segment intersrc(inter.getOrigine(),src.getPosition());

		for(std::vector<Visible*>::iterator o = obj->begin() ; o != obj->end(); ++o)
		{
			Intersection* interTemp = (*o)->estTraverse(intersrc);
			//si intersection trouvee
			//on met à jour la distance si nécessaire
			if(interTemp != NULL)
			{
				float d = inter.getOrigine().distanceAvecPoint(interTemp->getOrigine());
				if( 0.1 < d && inter.getOrigine().distanceAvecPoint(src.getPosition()) > interTemp->getOrigine().distanceAvecPoint(src.getPosition()))
				{
					e = 0;
				}
			}
			delete interTemp;
		}
		
		float refl = inter.getRefl();
		incident.prolongeSegment(inter);
		couleurCalculee = (1-refl)*couleurPropre(inter, src, e)+refl*drawPixel(incident, obj, src);
		
		return couleurCalculee;
	}
	else
	{
		RGB couleurCalculee(0,0,0);
		return couleurCalculee;
	}

	
}

#endif