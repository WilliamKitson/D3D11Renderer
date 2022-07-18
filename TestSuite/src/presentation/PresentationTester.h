#pragma once

#include <string>

#include "output/OutputTester.h"
#include "camera/CameraTester.h"
#include "RGB/RGBTester.h"

class PresentationTester
{
public:
	PresentationTester();
	~PresentationTester();

	std::string test();

private:
	std::string testOutput();
	std::string testCamera();
	std::string testRGB();
};
