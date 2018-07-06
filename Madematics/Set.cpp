#include "stdafx.h"
#include "Set.h"


Set::Set(std::vector<SetBorder*> *_borders, bool _startsAtMinusInf) : borders(_borders), startsAtMinusInfinity(_startsAtMinusInf)
{
	//TODO: check if borderset is ok! So no more than 2 with the same value, increasing order
}

bool Set::IsInSet(double x)
{
	bool currentSetIsIncluded = startsAtMinusInfinity;
	if (borders -> size() == 0)
		return currentSetIsIncluded;

	for (int i = 0; i < borders ->size(); i++)
	{
		if (currentSetIsIncluded) {
			if ((x < (*(*borders)[i]).x && (*(*borders)[i]).isOpen) || (x <= (*(*borders)[i]).x && !(*(*borders)[i]).isOpen))
			{
				return currentSetIsIncluded;
			}
		}
		else
		{
			if ((x <= (*(*borders)[i]).x && (*(*borders)[i]).isOpen) || (x < (*(*borders)[i]).x && !(*(*borders)[i]).isOpen))
			{
				return currentSetIsIncluded;
			}
		}
		currentSetIsIncluded = !currentSetIsIncluded;
	}
	return currentSetIsIncluded;//in case it's in the last subset
}

std::string Set::ToString()
{
	std::string s;
	bool subsetIncluded = startsAtMinusInfinity;
	if (subsetIncluded)
		s += "(-inf,";
	for (int i = 0; i < borders ->size(); i++)
	{
		if ((*(*borders)[i]).isOpen)
		{
			if (subsetIncluded)
			{
				s += std::to_string((*(*borders)[i]).x);
				s += ") ";
			}
			else
			{
				s += "(";
				s += std::to_string((*(*borders)[i]).x);
				s += ",";
			}
		}
		else
		{
			if (subsetIncluded)
			{
				s += std::to_string((*(*borders)[i]).x);
				s += "] ";
			}
			else
			{
				s += "[";
				s += std::to_string((*(*borders)[i]).x);
				s += ",";
			}
		}
		subsetIncluded = !subsetIncluded;
	}
	
	if (subsetIncluded)
		s += "+inf)";

	return s;
}