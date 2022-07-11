#pragma once

#include <string>
#include "ShadersLoadVertexTest.h"

class ShadersLoadTester
{
public:
	ShadersLoadTester();
	~ShadersLoadTester();

	std::string test();

private:
	std::string testVertex();
};
