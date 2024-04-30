#ifndef randNumGen
#define randNumGen

#include <iostream>
#include <random>

class RandNum
{
public:
	RandNum();
	int randomNum(int min, int max);

private:
	std::random_device rd;
};

#endif