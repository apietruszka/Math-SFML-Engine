#include "stdafx.h"
#include "FunkVisualiser.h"

FunkVisualiser::FunkVisualiser(double _cameraX, double _cameraY, double _singleUnitInPixels, std::vector<FunkVisualisable*> _functions) : cameraX(_cameraX), cameraY(_cameraY), singleUnitInPixels(_singleUnitInPixels), functionsToVisualise(_functions)
{

}

FunkVisualiser::FunkVisualiser(double _cameraX, double _cameraY, double _singleUnitInPixels) : cameraX(_cameraX), cameraY(_cameraY), singleUnitInPixels(_singleUnitInPixels)
{

}

void FunkVisualiser::SetCamera(double x, double y)
{
	cameraX = x;
	cameraY = y;
}

void FunkVisualiser::MoveCamera(double xOffset, double yOffset)
{
	cameraX += xOffset;
	cameraY += yOffset;
}

void FunkVisualiser::UpdateFunctions(int windowX, int windowY, int width, int hight)
{
	for (int i = 0; i < functionsToVisualise.size(); i++)
	{
		int size = 1 + 2 * functionsToVisualise[i]->divisions;
		if (functionsToVisualise[i]->update)
		{
			functionsToVisualise[i]->vs.resize(size);
		}

		//update every vertex of the given function!
		for (int j = 0; j < size; j++)
		{
			//TODO
		}
	}
}

void FunkVisualiser::UpdateFunctionsStandard2D(int windowX, int windowY, int width, int hight)
{
	for (int i = 0; i < functionsToVisualise.size(); i++)
	{
		if (functionsToVisualise[i]->update)
		{
			int size = functionsToVisualise[i]->divisions;
			if (functionsToVisualise[i]->update)
			{
				functionsToVisualise[i]->vs.resize(size);
			}

			//update every vertex of the given function!
			for (int j = 0; j < size; j++)
			{
				double x, y;
				double drawX, drawY;
				x = cameraX + (j / (size - 1.00001) - 0.5)*width / singleUnitInPixels;
				drawX = (j / (size - 1.0))*width;

				std::vector<double> buf;
				buf.push_back(x);
				y = functionsToVisualise[i]->f->F(&buf);
				drawY = hight / 2.0 - (y - cameraY)*singleUnitInPixels;

				sf::Vertex *v = &(functionsToVisualise[i]->vs[j]);
				v->position.x = drawX;
				v->position.y = drawY;

				//std::cout << j << "-th vertex. real values: (" << x << "," << y << "). Drawable values: (" << drawX << "," << drawY << ")" << std::endl;
				
				if (functionsToVisualise[i]->updateColor)
					v->color = functionsToVisualise[i]->color;
			}
		}
	}
}

void FunkVisualiser::Draw(sf::RenderWindow *window)
{
	for (int i = 0; i < functionsToVisualise.size(); i++)
		if(functionsToVisualise[i]->visualise)
			window->draw(functionsToVisualise[i]->vs);
}