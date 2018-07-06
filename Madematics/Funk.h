#pragma once
#ifndef _FUNK_H_
#define _FUNK_H_

#include "Set.h"
#include <iostream>

class Funk
{
	//add children with: possibility of getting the dirivative, the opposite func and such

	int numerOfArguments;
	int numberOfParams;//negative number = use as many as you want
	Set *domain;//TODO: add domain for every arg, for now its just for the first one
	//TODO: Vector of sets to indicate continuity; + for multiple variables

	std::vector<double>* params;
	double(*foo)(std::vector<double>* args, std::vector<double>* params);


public:
	Funk(int _numArgs, int _numParams, Set *_domain, double(*_f)(std::vector<double>*, std::vector<double>*), std::vector<double>*_params);
	double F(std::vector<double> *_args);
};

#endif