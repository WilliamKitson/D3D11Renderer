#pragma once

#include <string>

#include "default/PerObjectDefaultTester.h"
#include "update/PerObjectUpdateTester.h"

class PerObjectTester
{
public:
	PerObjectTester();
	~PerObjectTester();

	std::string test();

private:
	std::string testDefault();
	std::string testUpdate();
};
