#include "stdafx.h"
#include "Funk.h"

Funk::Funk(int _numArgs, int _numParams, Set *_domain, double(*_f)(std::vector<double>*, std::vector<double>*), std::vector<double>*_params) : numerOfArguments(_numArgs), numberOfParams(_numParams), domain(_domain), foo(_f), params(_params)
{
	if(numberOfParams>=0)
		if (numberOfParams != params->size())
		{
			//TODO:exception
			std::cout << "Wrong number of params" << std::endl;
		}
}

double Funk::F(std::vector<double> *_args)
{
	//we dont rly have to check that one if constructors dont mess up their jobs of checking input
	if ((*_args).size() != numerOfArguments)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
		//TODO: exception here!
	}
	
	if ((*_args).size() > 0)
	{
		if (!(*domain).IsInSet((*_args)[0]))
		{
			//std::cout << "Argument not in the domain" << std::endl;
			return 0;
			//TODO: exception here!
		}
	}

	return foo(_args, params);
}