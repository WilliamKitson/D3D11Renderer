#pragma once

#include <string>

#include "resolution/ResolutionTester.h"
#include "coordinates1D/Coordinates1DTester.h"

class DomainTester
{
public:
	DomainTester();
	~DomainTester();

	std::string test();

private:
	std::string testResolution();
	std::string testCoordinates1D();
};
