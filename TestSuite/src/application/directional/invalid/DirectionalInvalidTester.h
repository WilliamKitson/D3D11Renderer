#pragma once

#include <string>

#include "DirectionalInvalidInitialiseTest.h"
#include "DirectionalInvalidBindTest.h"
#include "DirectionalInvalidApplyTest.h"

class DirectionalInvalidTester
{
public:
	DirectionalInvalidTester();
	~DirectionalInvalidTester();

	std::string test();

private:
	std::string testInitialise();
	std::string testBind();
	std::string testApply();
};
