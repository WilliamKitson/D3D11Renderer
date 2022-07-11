#pragma once

#include <string>

#include "ShadersLoadVertexTest.h"
#include "ShadersLoadPixelTest.h"
#include "ShadersLoadInputTest.h"

class ShadersLoadTester
{
public:
	ShadersLoadTester();
	~ShadersLoadTester();

	std::string test();

private:
	std::string testVertex();
	std::string testPixel();
	std::string testInput();
};
