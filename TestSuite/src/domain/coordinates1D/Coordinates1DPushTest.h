#pragma once

#include <string>
#include "Coordinates1D.h"

class Coordinates1DPushTest
{
public:
	Coordinates1DPushTest();
	~Coordinates1DPushTest();

	std::string test();

private:
	int itterations;
	int successes;
};
