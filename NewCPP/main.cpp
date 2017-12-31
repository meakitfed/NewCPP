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

	return 0;
}