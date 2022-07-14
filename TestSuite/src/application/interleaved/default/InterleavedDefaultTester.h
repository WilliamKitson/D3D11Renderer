#pragma once

#include <string>

#include "InterleavedDefaultVertexTest.h"
#include "InterleavedDefaultIndexTest.h"

class InterleavedDefaultTester
{
public:
	InterleavedDefaultTester();
	~InterleavedDefaultTester();

	std::string test();

private:
	std::string testVertex();
	std::string testIndex();
};
