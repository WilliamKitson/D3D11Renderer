#pragma once

#include <string>
#include "InterleavedDefaultTest.h"

class InterleavedTester
{
public:
	InterleavedTester();
	~InterleavedTester();

	std::string test();

private:
	std::string testDefault();
};
