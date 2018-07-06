#pragma once
#ifndef _LINEAR	_TRANSFORMATION_H_
#define _LINEAR	_TRANSFORMATION_H_

#include <iostream>
#include <stdlib.h>
#include <vector>

class LinearTransformation
{
	int n, m;
	std::vector<std::vector<double>> matrix;

public:
	LinearTransformation(int _n, int _m, std::vector<std::vector<double>> _matrix);
	std::vector<double> TransformPoint(std::vector<double> point);
};

#endif