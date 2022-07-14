#pragma once

#include <string>

#include "camera/CameraTester.h"
#include "RGB/RGBTester.h"

class PresentationTester
{
public:
	PresentationTester();
	~PresentationTester();

	std::string test();

private:
	std::string testCamera();
	std::string testRGB();
};
