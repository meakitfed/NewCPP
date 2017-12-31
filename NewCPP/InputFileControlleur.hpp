#ifndef InputFileControlleur_H 
#define InputFileControlleur_H


#include <iostream>

#include <limits>
#include <cstdlib>
#include <string>
#include <fstream>

#include "Pos.hpp"
#include "RGB.hpp"
#include "Scene.hpp"
#include "Source.hpp"
#include "Sphere.hpp"


class InputFileControlleur
{
	Scene* scene;
	std::string inputFileName;
	std::ifstream inputFile;
	
	
	public :
	InputFileControlleur(Scene* s,std::string inputPath): scene(s),inputFileName(inputPath)
	{
		inputFile.open(inputFileName,std::ios::in);
		if(!inputFile)
        {
            std::cout << "problème lors de l'ouverture de " << inputFileName << std::endl;
        }
        else
        {
            std::cout << inputFileName <<" a été ouvert !" << std::endl;
        }
	};
	~InputFileControlleur() { delete scene;}


	void sauteCommentaires();
	void sauteBlancs();
	void sauteCommentairesEtBlancs();
	int horizontalResolution();
	RGB recupNextRGB();
	int recupNextCouleur();
	void objectsInScene();
	void parseInputFile();
	Pos recupNextPos();
	float recupNextFloat();
	Visible* constrObject(std::string s);

	
};

void InputFileControlleur::parseInputFile()
{
	std::cout << "\nVoici les données enregistrés dans la scène : \n\n" ;
	//Position de la caméra 
	sauteCommentairesEtBlancs();
	scene->setCameraPosition(recupNextPos());
	std::cout << scene->getCamera() << std::endl;

	//Initialisation de l'écran 
	sauteCommentairesEtBlancs();
	Pos p1(recupNextPos());
	sauteCommentairesEtBlancs();
	Pos p2(recupNextPos());
	sauteCommentairesEtBlancs();
	Pos p3(recupNextPos());
	sauteCommentairesEtBlancs();
	int r(recupNextFloat());
	Ecran e(p1,p2,p3,r);
	scene->setEcran(e);
	std::cout << scene->getEcran() << std::endl;	

	//Couleur du fond
	sauteCommentairesEtBlancs();
	RGB c(recupNextRGB());
	scene->setBackgroundColor(c);
	std::cout << "backgroundColor : " << scene->getBackgroundColor() << std::endl;

	//Position de la lumière
	sauteCommentairesEtBlancs();
	Pos p4(recupNextPos());
	sauteCommentairesEtBlancs();
	RGB c1(recupNextRGB());
	Source s(p4,c1);
	scene->setSource(s);
	std::cout << scene->getSource() << std::endl;

	//Construction des objets
	sauteCommentairesEtBlancs();
	objectsInScene();
}

void InputFileControlleur::sauteCommentaires()
{
	std::string temp;
	while(!inputFile.eof() && (inputFile.peek() == '#' || inputFile.peek()=='\n')) std::getline(inputFile, temp);
}

void InputFileControlleur::sauteBlancs()
{
	while(!inputFile.eof() && (inputFile.peek() == ' ' || inputFile.peek() == '\n')) inputFile.ignore(1);
}

void InputFileControlleur::sauteCommentairesEtBlancs()
{
	while(!inputFile.eof() && (inputFile.peek() == '#' || inputFile.peek()=='\n' || inputFile.peek() == ' '))
	{
		sauteBlancs();
		sauteCommentaires();
	}
}

RGB InputFileControlleur::recupNextRGB()
{
	int r(recupNextCouleur());
	int g(recupNextCouleur());
	int b(recupNextCouleur());
	RGB rgb(r,g,b);
	return rgb;
}

int InputFileControlleur::recupNextCouleur()
{
	std::string s = "";
	if(inputFile.peek() == ' ')
	{
		inputFile.ignore(std::numeric_limits<std::streamsize>::max(),' ');
	}
	while(inputFile.peek() != ' ' && inputFile.peek() != '\n')
	{
		s+=inputFile.get();
	}
	int i;
	i = std::stoi(s);

	if(i<0 || i>255)
	{
		std::cout << "Erreur dans le fichier, Couleur RGB inconnue" << std::endl;
		return -1;
	}
	else
	{
		return i;
	}
	
}

Pos InputFileControlleur::recupNextPos()
{
	float x(recupNextFloat());
	float y(recupNextFloat());
	float z(recupNextFloat());
	Pos pos(x,y,z);
	return pos;
}

float InputFileControlleur::recupNextFloat()
{
	std::string s;
	if(inputFile.peek() == ' ')
	{
		inputFile.ignore(std::numeric_limits<std::streamsize>::max(),' ');
	}	
	while(!inputFile.eof() && (inputFile.peek() != ' ' && inputFile.peek() != '\n'))
	{
		s+=inputFile.get();
	} 
	return std::strtof(s.c_str(),0);
}

void InputFileControlleur::objectsInScene()
{
	
	while(!inputFile.eof())
	{
		std::string s;
		sauteCommentairesEtBlancs();
		while(!inputFile.eof() && inputFile.peek() != ':')
		{
			s+=inputFile.get();
		}
		if(!inputFile.eof())
		{
			if(inputFile.peek() == ':')
			{
				s+=inputFile.get();
			}
			if(s.compare("sphere:")==0)
			{
				Visible* o;
				o = constrObject(s);
				scene->getListObjects()->push_back(o);
			}
			else
			{
				std::cout << "attention vous avez fait une erreur en essayant de créer un objet, voici la syntaxe que vous avez utilisé : " << s << std::endl;
				exit(0);
			}
		}
	}
}

Visible* InputFileControlleur::constrObject(std::string s)
{
	if(s.compare("sphere:")==0)
	{
		Pos p(recupNextPos());

		sauteCommentairesEtBlancs();
		float ray(recupNextFloat());

		sauteCommentairesEtBlancs();
		RGB c(recupNextRGB());

		sauteCommentairesEtBlancs();
		float ref(recupNextFloat());

		Sphere* sphere = new Sphere(p,c,ref,ray);
		std::cout << "création de " << *sphere << std::endl;
		return sphere;
	}
	else
	{
		return NULL;
	}
}

#endif