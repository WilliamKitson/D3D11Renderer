#pragma once

#include <string>
#include "default/PerObjectDefaultTester.h"

class PerObjectTester
{
public:
	PerObjectTester();
	~PerObjectTester();

	std::string test();

private:
	std::string testDefault();
};
