#pragma once

#include <string>
#include "presentation/PresentationTester.h"

class SubordinateTester
{
public:
	SubordinateTester();
	~SubordinateTester();

	std::string test();

private:
	std::string testPresentation();
};
