#pragma once

#include <string>

#include "default/PerSceneDefaultTester.h"
#include "reload/PerSceneReloadTester.h"
#include "apply/PerSceneApplyTester.h"

class PerSceneTester
{
public:
	PerSceneTester();
	~PerSceneTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();
	std::string testApply();
};
