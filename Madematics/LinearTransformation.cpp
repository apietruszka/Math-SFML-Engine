#include "stdafx.h"
#include "LineaTransformation.h"

LinearTransformation::LinearTransformation(int _n, int _m, std::vector<std::vector<double>> _matrix) : n(_n), m(_m), matrix(_matrix)
{

}


std::vector<double> LinearTransformation::TransformPoint(std::vector<double> point)
{
	std::vector<double> newPoint = point;
	for (int i = 0; i < m; i++)
	{
		newPoint[i] = 0;
		for (int j = 0; j < n; j++)
		{
			//if its not supposed to be linear, use some different formula in here!
			newPoint[i] += matrix[i][j] * point[j];
		}
	}
	return newPoint;
}