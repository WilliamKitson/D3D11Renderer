#pragma once

#include <string>

#include "Coordinates2DIndexDefaultTest.h"
#include "Coordinates2DIndexMinimumTest.h"
#include "Coordinates2DIndexMaximumTest.h"

class Coordinates2DIndexTester
{
public:
	Coordinates2DIndexTester();
	~Coordinates2DIndexTester();

	std::string test();

private:
	std::string testDefault();
	std::string testMinimum();
	std::string testMaximum();
};
