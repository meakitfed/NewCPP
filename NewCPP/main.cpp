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
#include "Triangle.hpp"

using namespace std;

int main()
{

	Scene* s = new Scene();
	InputFileControlleur f(s,"fichier");
	f.parseInputFile();
	OutputFileControlleur o(s,"hey");
	o.writeInOutputFile();

	/*std::vector<Visible*>* objects = new std::vector<Visible*>;
	Pos p1(1,0,1);
	Pos p2(0,1,1);
	Pos p3(-1,0,2);
	Pos p(0,0.5,1);
	Pos p4(0,0,0);
	Segment s(p4,p);
	
	RGB c(255,255,5);
	Triangle* triangle = new Triangle(p1,p2,p3,c,0.3);
	objects->push_back(triangle);
	Intersection* i = objects->at(0)->estTraverse(s);
	cout << i->getOrigine() << endl;*/

	return 0;
}