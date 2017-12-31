#ifndef OutputFileControlleur_H 
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


class OutputFileControlleur
{
	Scene* scene;
	std::string outputFileName;
	std::ofstream outputFile;
	
	
	public :
	OutputFileControlleur(Scene* s,std::string outputPath): scene(s), outputFileName(outputPath)
	{
		outputFile.open(outputFileName,std::ios::out | std::ios::trunc);
		if(!outputFile)
        {
            std::cout << "problème lors de l'ouverture de " << outputFileName << std::endl;
        }
        else
        {
            std::cout << outputFileName <<" a été ouvert !" << std::endl;
        }
	};
	void writeInOutputFile()
	{
		scene->getEcran().initEcran(scene->getBackgroundColor());
		scene->getEcran().drawImage(scene->getCamera().getPosition(), scene->getListObjects(), scene->getSource());
		outputFile << "P3" << std::endl;
		outputFile << scene->getEcran().getResolution() << " " << scene->getEcran().getResolution() << std::endl;
		outputFile << "255" << std::endl;
		int i = 0;
		int j = 0;
		for(i=0; i<scene->getEcran().getResolution(); i++)
		{
			for(j=0; j<scene->getEcran().getResolution(); j++)
			{
				outputFile << scene->getEcran().getPixel()[i][j].getColor();
				if(j+1!=scene->getEcran().getResolution())
				{
					outputFile << " ";
				}
			
			}
			outputFile << std::endl;
		}
		outputFile.close();

	}

	
};
#endif