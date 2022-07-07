#pragma once

#include <string>
#include "Coordinates1DIndexDefaultTest.h"

class Coordinates1DIndexTester
{
public:
	Coordinates1DIndexTester();
	~Coordinates1DIndexTester();

	std::string test();

private:
	std::string testDefault();
};
