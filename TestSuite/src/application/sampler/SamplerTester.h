#pragma once

#include <string>

#include "SamplerDefaultTest.h"
#include "SamplerReloadTest.h"
#include "invalid/SamplerInvalidTester.h"

class SamplerTester
{
public:
	SamplerTester();
	~SamplerTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();
	std::string testInvalid();
};
