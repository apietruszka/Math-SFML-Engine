#include "Test.h"
#include "stdafx.h"

int fact(int n)
{
	int buf = 1;
	for (int i = 2; i <= n; i++)
		buf *= i;
	return buf;
}