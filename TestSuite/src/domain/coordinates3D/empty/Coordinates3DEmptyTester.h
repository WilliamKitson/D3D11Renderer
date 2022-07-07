#pragma once

#include <string>

#include "Coordinates3DEmptyXTest.h"
#include "Coordinates3DEmptyYTest.h"
#include "Coordinates3DEmptyZTest.h"

class Coordinates3DEmptyTester
{
public:
	Coordinates3DEmptyTester();
	~Coordinates3DEmptyTester();

	std::string test();

private:
	std::string testX();
	std::string testY();
	std::string testZ();
};
