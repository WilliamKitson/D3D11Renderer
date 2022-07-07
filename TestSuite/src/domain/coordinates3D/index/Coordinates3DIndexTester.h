#pragma once

#include <string>

#include "Coordinates3DIndexDefaultTest.h"
#include "Coordinates3DIndexMinimumTest.h"
#include "Coordinates3DIndexMaximumTest.h"

class Coordinates3DIndexTester
{
public:
	Coordinates3DIndexTester();
	~Coordinates3DIndexTester();

	std::string test();

private:
	std::string testDefault();
	std::string testMinimum();
	std::string testMaximum();
};
