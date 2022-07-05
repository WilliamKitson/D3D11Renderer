#pragma once

#include <string>

#include "camera/CameraTester.h"
#include "RGB/RGBTester.h"
#include "RGBA/RGBATester.h"
#include "CBufferPerObject/CBufferPerObjectTester.h"
#include "CBufferPerScene/CBufferPerSceneTester.h"

class PresentationTester
{
public:
	PresentationTester();
	~PresentationTester();

	std::string test();

private:
	std::string testCamera();
	std::string testRGB();
	std::string testRGBA();
	std::string testCBufferPerObject();
	std::string testCBufferPerScene();
};
