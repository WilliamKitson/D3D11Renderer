#pragma once

#include <string>
#include "default/GeometryDefaultTester.h"

class GeometryTester
{
public:
	GeometryTester();
	~GeometryTester();

	std::string test();

private:
	std::string testDefault();
};
