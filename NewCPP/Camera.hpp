#ifndef CAMERA_H 
#define CAMERA_H 


#include <iostream>
#include <cstdlib>
#include <string>
#include "Objets.hpp"
#include "Pos.hpp"

class Camera 
{
	Pos position;
	public :
	Camera() {};
	void afficher(std::ostream &flux) const;
	Pos getPosition(){return position;}
	void setPosition(Pos p){position=p;}
};

void Camera::afficher(std::ostream &flux) const
{
    flux << "Position Camera :" << position;
}

std::ostream &operator<<(std::ostream &flux, Camera const& cam)
{
    cam.afficher(flux) ;
    return flux;
}
#endif