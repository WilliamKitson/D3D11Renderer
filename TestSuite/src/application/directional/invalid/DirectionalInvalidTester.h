#pragma once

#include <string>

#include "DirectionalInvalidInitialiseTest.h"
#include "DirectionalInvalidBindTest.h"

class DirectionalInvalidTester
{
public:
	DirectionalInvalidTester();
	~DirectionalInvalidTester();

	std::string test();

private:
	std::string testInitialise();
	std::string testBind();
};
