#pragma once

#include <string>
#include "ImplimentationObjectDefaultTest.h"

class ImplimentationObjectTester
{
public:
	ImplimentationObjectTester();
	~ImplimentationObjectTester();

	std::string test();

private:
	std::string testDefault();
};
