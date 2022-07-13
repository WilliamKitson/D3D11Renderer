#pragma once

#include <string>

#include "default/DirectionalDefaultTester.h"
#include "reload/DirectionalReloadTester.h"
#include "apply/DirectionalApplyTester.h"

class DirectionalTester
{
public:
	DirectionalTester();
	~DirectionalTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();
	std::string testApply();
};
