#pragma once

#include <string>

#include "InterleavedDefaultTest.h"
#include "InterleavedReloadTest.h"

class InterleavedTester
{
public:
	InterleavedTester();
	~InterleavedTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();
};
