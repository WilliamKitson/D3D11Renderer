#pragma once

#include <string>

#include "default/DirectionalDefaultTester.h"
#include "reload/DirectionalReloadTester.h"

class DirectionalTester
{
public:
	DirectionalTester();
	~DirectionalTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();
};
