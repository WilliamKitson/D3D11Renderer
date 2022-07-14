#pragma once

#include <string>

#include "InterleavedDefaultTest.h"
#include "InterleavedReloadTest.h"
#include "InterleavedStrideTest.h"
#include "InterleavedOffsetTest.h"
#include "InterleavedTopologyTest.h"
#include "invalid/InterleavedInvalidTester.h"

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
	std::string testOffset();
	std::string testTopology();
	std::string testInvalid();
};
