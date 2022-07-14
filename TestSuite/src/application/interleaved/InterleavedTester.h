#pragma once

#include <string>

#include "InterleavedDefaultTest.h"
#include "InterleavedReloadTest.h"
#include "InterleavedStrideTest.h"

class InterleavedTester
{
public:
	InterleavedTester();
	~InterleavedTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();
	std::string testStride();
};
