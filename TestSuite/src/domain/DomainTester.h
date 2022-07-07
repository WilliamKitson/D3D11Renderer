#pragma once

#include <string>

#include "resolution/ResolutionTester.h"
#include "coordinates2D/Coordinates2DTester.h"

class DomainTester
{
public:
	DomainTester();
	~DomainTester();

	std::string test();

private:
	std::string testResolution();
	std::string testCoordinates2D();
};
