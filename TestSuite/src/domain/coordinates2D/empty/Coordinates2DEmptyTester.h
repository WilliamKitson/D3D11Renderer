#pragma once

#include <string>

#include "Coordinates2DEmptyXTest.h"
#include "Coordinates2DEmptyYTest.h"

class Coordinates2DEmptyTester
{
public:
	Coordinates2DEmptyTester();
	~Coordinates2DEmptyTester();

	std::string test();

private:
	std::string testX();
	std::string testY();
};
