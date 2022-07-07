#pragma once

#include <string>

#include "resolution/ResolutionTester.h"
#include "coordinates3D/Coordinates3DTester.h"

class DomainTester
{
public:
	DomainTester();
	~DomainTester();

	std::string test();

private:
	std::string testResolution();
	std::string testCoordinates3D();
};
