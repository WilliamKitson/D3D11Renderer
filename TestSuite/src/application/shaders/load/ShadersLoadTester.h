#pragma once

#include <string>

#include "ShadersLoadVertexTest.h"
#include "ShadersLoadPixelTest.h"

class ShadersLoadTester
{
public:
	ShadersLoadTester();
	~ShadersLoadTester();

	std::string test();

private:
	std::string testVertex();
	std::string testPixel();
};
