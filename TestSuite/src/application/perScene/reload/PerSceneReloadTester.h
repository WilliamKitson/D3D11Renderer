#pragma once

#include <string>
#include "PerSceneReloadWorldViewProjectionTest.h"

class PerSceneReloadTester
{
public:
	PerSceneReloadTester();
	~PerSceneReloadTester();

	std::string test();

private:
	std::string testWorldViewProjection();
};
