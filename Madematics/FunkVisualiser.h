#pragma once
#ifndef _FUNK_VISUALISER_H_
#define _FUNK_VISUALISER_H_

#include "Funk.h"
#include <SFML/Graphics.hpp>

extern struct FunkVisualisable
{
	Funk *f;
	sf::Color color;
	int divisions;
	bool update; //do you want to update the vertex array in the next iteration
	bool updateColor;
	bool visualise; //do you want to show the vertex array on the screen in the next iteration
	sf::VertexArray vs;
};

class FunkVisualiser
{
	//this class is responsible for the drawing of a function, precision, colors, managing the window
	double cameraX;
	double cameraY;
	std::vector<FunkVisualisable*> functionsToVisualise; //we're not using pointer to a vector, because 1) there is going to be few funk visualisers, 2) some might use a vector from the main function, some might need to generate a new one, so we dont want to get messy and remember where the vector came from(to know whether we should clear it or not)
	double singleUnitInPixels;

	//how do we work?
	//start (0,0)
	//do (currentX, currentY)-=i*scale division times, then go (0,0), do current vec += i*scale division times
	//for each move, add a point (currentX,0)+(0,f(currentX))

public:
	FunkVisualiser(double _cameraX, double _cameraY, double _singleUnitInPixels, std::vector<FunkVisualisable*> _functions);
	FunkVisualiser(double _cameraX, double _cameraY, double _singleUnitInPixels);
	void SetCamera(double x, double y);
	void MoveCamera(double xOffset, double yOffset);
	void UpdateFunctions(int windowX, int windowY, int width, int hight);//TODO
	void UpdateFunctionsStandard2D(int windowX, int windowY, int width, int hight);
	void Draw(sf::RenderWindow *window);
};


#endif