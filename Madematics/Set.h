#pragma once
#ifndef _SET_H_
#define _SET_H_
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

extern struct SetBorder
{
	double x;
	bool isOpen;
};

class Set
{
	//TODO: Add possibility of adding discrete sets f.e. {1,2,4,7}
	//TODO: Add possibility of adding f.e. (k, k+0.5)

	

	bool startsAtMinusInfinity;//If it's false, our set will start from the first border!
	std::vector<SetBorder*> *borders;

public:
	Set(std::vector<SetBorder*> *_borders, bool _startsAtMinusInf);
	bool IsInSet(double x);//for checking if a value is in set
	std::string ToString();
};

#endif