#pragma once

#include <string>

#include "Coordinates1DIndexDefaultTest.h"
#include "Coordinates1DIndexMinimumTest.h"
#include "Coordinates1DIndexMaximumTest.h"

class Coordinates1DIndexTester
{
public:
	Coordinates1DIndexTester();
	~Coordinates1DIndexTester();

	std::string test();

private:
	std::string testDefault();
	std::string testMinimum();
	std::string testMaximum();
};
