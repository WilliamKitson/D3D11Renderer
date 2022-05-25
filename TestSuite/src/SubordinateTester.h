#pragma once

#include <string>
#include "domain/DomainTester.h"
#include "presentation/PresentationTester.h"

class SubordinateTester
{
public:
	SubordinateTester();
	~SubordinateTester();

	std::string test();

private:
	std::string testDomain();
	std::string testPresentation();
};
