#pragma once

#include <string>
#include "DirectionalInvalidInitialiseTest.h"

class DirectionalInvalidTester
{
public:
	DirectionalInvalidTester();
	~DirectionalInvalidTester();

	std::string test();

private:
	std::string testInitialise();
};
