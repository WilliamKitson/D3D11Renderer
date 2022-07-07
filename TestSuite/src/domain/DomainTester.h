#pragma once

#include <string>
#include "resolution/ResolutionTester.h"

class DomainTester
{
public:
	DomainTester();
	~DomainTester();

	std::string test();

private:
	std::string testResolution();
};
