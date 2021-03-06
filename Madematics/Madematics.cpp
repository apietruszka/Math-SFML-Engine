#include "stdafx.h"
#include "Test.h"
#include "Set.h"
#include "Funk.h"
#include "FunkVisualiser.h"
#include "LineaTransformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>


double xSqr(std::vector<double>* args, std::vector<double>* params)
{
	//assumptions - args is a 1 arg vec
	return (*params)[0] *(*args)[0] * (*args)[0];
}

double xSqr2(std::vector<double>* args, std::vector<double>* params)
{
	//assumptions - args is a 1 arg vec
	return (*params)[0] *(*args)[0] * (*args)[0];
}

double x2(std::vector<double>* args, std::vector<double>* params)
{
	return (*params)[0] * (*args)[0];
}

sf::VertexArray Lerp(sf::VertexArray *x, sf::VertexArray *y, float value, sf::Color color)
{
	//check conditions
	if (x->getVertexCount() != y->getVertexCount())
	{
		std::cout << "Lerp error" << std::endl;
	}

	sf::VertexArray ret;
	ret.setPrimitiveType(x->getPrimitiveType());
	for (int i = 0; i < x->getVertexCount(); i++)
	{
		sf::Vector2f pos = (*x)[i].position + ((*y)[i].position - ((*x)[i].position))*value;
		ret.append(sf::Vertex(pos, color));
	}
	return ret;
}



int main()
{
	const int windowX = 800;
	const int windowY = 400;
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Madematics!");

	time_t start, end;
	double frameTime = 0.00000000001;//to avoid dividing by zero if its used in first frame

	std::vector<SetBorder*> set;
	SetBorder s1,s2;
	
	s1.isOpen = false;
	s2.isOpen = true;
	s1.x = 0;
	s2.x = 100;
	set.push_back(&s1);
	
	Set domain(&set, false);

	std::vector<double> params1;
	params1.push_back(0.01);
	std::vector<double> params2;
	params2.push_back(0.02);

	Funk xSqrFunc(1,1, &domain, xSqr, &params1);
	Funk xSqr2Func(1,1, &domain, xSqr2, &params2);

	std::vector<double> funcArgs;

	

	std::vector<FunkVisualisable*> functionsToVisualise;

	FunkVisualisable sqrVisual;
	sqrVisual.color = sf::Color::Yellow;
	sqrVisual.divisions = 20;
	sqrVisual.f = &xSqrFunc;
	sqrVisual.update = sqrVisual.updateColor = sqrVisual.visualise = true;
	sqrVisual.vs.setPrimitiveType(sf::PrimitiveType::LinesStrip);
	functionsToVisualise.push_back(&sqrVisual);

	FunkVisualisable sqr2Visual;
	sqr2Visual.color = sf::Color::Red;
	sqr2Visual.divisions = 20;
	sqr2Visual.f = &xSqr2Func;
	sqr2Visual.update = sqr2Visual.updateColor = sqr2Visual.visualise = true;
	sqr2Visual.vs.setPrimitiveType(sf::PrimitiveType::LinesStrip);
	functionsToVisualise.push_back(&sqr2Visual);

	

	int unitsPerPixel = 1;
	double cameraX = 100;
	double cameraY = 100;
	FunkVisualiser visualiser(cameraX, cameraY, unitsPerPixel, functionsToVisualise);

	visualiser.UpdateFunctionsStandard2D(0, 0, windowX, windowY);
	sf::VertexArray lerp1= sqrVisual.vs;
	lerp1.setPrimitiveType(sf::PrimitiveType::LinesStrip);




	while (window.isOpen())
	{
		time(&start);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		visualiser.UpdateFunctionsStandard2D(0, 0, windowX, windowY);
		lerp1 = Lerp(&lerp1, &sqr2Visual.vs, 0.1*frameTime, sf::Color(255, 160, 0, 150));
		visualiser.Draw(&window);
		window.draw(lerp1);


		window.display();
		time(&end);
		frameTime = difftime(end, start);
	}

	return 0;
}