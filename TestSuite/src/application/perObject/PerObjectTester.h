#pragma once

#include <string>

#include "default/PerObjectDefaultTester.h"
#include "reload/PerObjectReloadTester.h"
#include "apply/PerObjectApplyTester.h"
#include "invalid/PerObjectInvalidTester.h"

class PerObjectTester
{
public:
	PerObjectTester();
	~PerObjectTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();
	std::string testApply();
	std::string testInvalid();
};
