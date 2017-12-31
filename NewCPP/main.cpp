#include <iostream>
#include <cstdlib>
#include <string>
#include "Pos.hpp"
#include "RGB.hpp"
#include "InputFileControlleur.hpp"
#include "OutputFileControlleur.hpp"
#include "Objets.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Source.hpp"
#include "Visible.hpp"
#include "Intersection.hpp"
#include "Segment.hpp"

using namespace std;

int main()
{

	Scene* s = new Scene();
	InputFileControlleur f(s,"fichier");
	f.parseInputFile();
	OutputFileControlleur o(s,"hey");
	o.writeInOutputFile();

	/*std::vector<Visible*>* objects = new std::vector<Visible*>;
	Pos p1(100,100,0);
	Pos p2(2,4,2);
	Segment s(p1,p2);
	Pos p(90,95,60);
	RGB c(255,255,5);
	Sphere* sphere = new Sphere(p,c,0.3,2);
	objects->push_back(sphere);
	Intersection* i = objects->at(0)->estTraverse(s);*/

	return 0;
}