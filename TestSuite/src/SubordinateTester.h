#pragma once

#include <string>

#include "domain/DomainTester.h"
#include "application/ApplicationTester.h"
#include "presentation/PresentationTester.h"

class SubordinateTester
{
public:
	SubordinateTester(HINSTANCE, int);
	~SubordinateTester();

	std::string test();

private:
	std::string testDomain();
	std::string testApplication();
	std::string testPresentation();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
