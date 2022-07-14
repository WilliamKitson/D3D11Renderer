#pragma once

#include <string>
#include "InterleavedDefaultVertexTest.h"

class InterleavedDefaultTester
{
public:
	InterleavedDefaultTester();
	~InterleavedDefaultTester();

	std::string test();

private:
	std::string testVertex();
};
