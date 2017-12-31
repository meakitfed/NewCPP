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
	OutputFileControlleur o(s,"image.ppm");
	o.writeInOutputFile();
	//problème d'appel des destructeurs, pas eu le temps de comprendre.
	//delete s;
	return 0;
}