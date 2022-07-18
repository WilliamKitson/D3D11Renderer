#pragma once

#include <string>

#include "OutputWidthTest.h"
#include "OutputHeightTest.h"

class OutputTester
{
public:
	OutputTester();
	~OutputTester();

	std::string test();

private:
	std::string testWidth();
	std::string testHeight();
};
