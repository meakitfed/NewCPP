#ifndef PIXEL_H
#define PIXEL_H

#include "RGB.hpp"
#include "Visible.hpp"
#include "Pos.hpp"
#include "Intersection.hpp"
#include "Segment.hpp"

class Pixel 
{
	Pos position;
	RGB couleur;

	public :
	Pixel() {};
	Pixel(Pos p, RGB c) : position(p), couleur(c) {};
	RGB getColor(){return couleur;}
	void setColor(RGB c){couleur=c;}
	Pos getPosition(){return position;}
	void setPosition(Pos p){position=p;}
	void drawPixel(Pos posCam, std::vector<Visible*>* obj, Source src);


};

void Pixel::drawPixel(Pos posCam, std::vector<Visible*>* obj, Source src){
	float distanceAvecPixel=-1;
	Intersection inter;
	Visible* objTemp;
	//creation du segment qui part de cam vers le pixel
	Segment s(posCam,this->getPosition());

	//pour tout les objets visibles
	for(std::vector<Visible*>::iterator o = obj->begin() ; o != obj->end(); ++o)
	{
		Intersection* interTemp = (*o)->estTraverse(s);

		//si intersection trouvee
		//on met à jour la distance si nécessaire
		if(interTemp != NULL)
		{
			//std::cout << "lol" << std::endl;
			float d = s.getOrigine().distanceAvecPoint(interTemp->getOrigine());
			if(distanceAvecPixel > d || distanceAvecPixel==-1)
			{
				inter = *interTemp;
				distanceAvecPixel = d;
				objTemp =*o;
				//this->setColor(inter.getColor());
			}
		}
		delete interTemp;
	}

	int e=1;
	if(distanceAvecPixel!=-1)
	{
		//rajouter calcul d'obsacle entre inter et src
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
				if( 0.1 < d)
				{
					//std::cout << "lol" << std::endl;
					e = 0;
				}
			}
			delete interTemp;
		}
		
		couleurCalculee = e*cos(objTemp->calculerAngle(inter, src.getPosition()))*(inter.getColor()*src.getColor());
		
		this->setColor(couleurCalculee);
	}	
	
}

#endif