#pragma once

#include <string>
#include "OutputWidthTest.h"

class OutputTester
{
public:
	OutputTester();
	~OutputTester();

	std::string test();

private:
	std::string testWidth();
};
