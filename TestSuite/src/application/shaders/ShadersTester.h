#pragma once

#include <string>

#include "load/ShadersLoadTester.h"
#include "invalid/ShadersInvalidTester.h"

class ShadersTester
{
public:
	ShadersTester();
	~ShadersTester();

	std::string test();

private:
	std::string testLoad();
	std::string testInvalid();
};
