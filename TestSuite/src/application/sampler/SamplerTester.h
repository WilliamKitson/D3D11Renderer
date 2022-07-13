#pragma once

#include <string>
#include "SamplerDefaultTest.h"

class SamplerTester
{
public:
	SamplerTester();
	~SamplerTester();

	std::string test();

private:
	std::string testDefault();
};
