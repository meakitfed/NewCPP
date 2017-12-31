#include <iostream>
#include <cstdlib>
#include <string>
#include "Pos.hpp"
#include "RGB.hpp"
#include "Intersection.hpp"
#include "Segment.hpp"
#include "Objets.hpp"
#include "Visible.hpp"
#include "Sphere.hpp"
#include "InputFileControlleur.hpp"
#include "OutputFileControlleur.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Source.hpp"


using namespace std;

int main()
{
	/*Scene* s = new Scene();
	InputFileControlleur f(s,"fichier");
	f.parseInputFile();
	OutputFileControlleur o(s,"hey");
	o.writeInOutputFile();*/

	Pos p(2,0,0);
	Pos p1(0,0,0);
	Pos p2(1,0,0);
	RGB color(0,0,0);
	Sphere s(p, color, 0, 1);
	Segment seg(p1,p2);
	Intersection* i = s.estTraverse(seg);

	cout << i->getOrigine().getX() << " puis normale " << i->getNormale().getX() << endl;

	return 0;
}