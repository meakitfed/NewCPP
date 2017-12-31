#ifndef SCENE_H   
#define SCENE_H 

#include <vector>

#include "Source.hpp"
#include "Visible.hpp"

#include "Pos.hpp"
#include "Camera.hpp"
#include "Ecran.hpp"
#include "RGB.hpp"

class Scene
{
	Camera camera;
	Ecran ecran;
	RGB backgroundColor;
	Source src;
	std::vector<Visible*>* objects = new std::vector<Visible*>;

	public :
	Scene(){}
	~Scene(){}
	Camera getCamera(){return camera;}
	Ecran getEcran(){return ecran;}
	void setBackgroundColor(RGB c){backgroundColor = c;}
	RGB getBackgroundColor(){return backgroundColor;}
	void setEcran(Ecran e){ecran = e;}
	void setSource(Source s){src = s;}
	std::vector<Visible*>* getListObjects(){return objects;}
	Source getSource(){return src;}
	void setCameraPosition(Pos p){camera.setPosition(p);}
};

#endif