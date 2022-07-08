#pragma once

#include <string>

#include "default/GeometryDefaultTester.h"
#include "reload/GeometryReloadTester.h"

class GeometryTester
{
public:
	GeometryTester();
	~GeometryTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();
};
