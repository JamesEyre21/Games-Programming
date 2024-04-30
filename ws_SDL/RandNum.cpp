#include "RandNum.h"


RandNum::RandNum()
{
}

int RandNum::randomNum(int min, int max)
{
	std::uniform_int_distribution<int>dist(min, max);

	return dist(rd);
}
