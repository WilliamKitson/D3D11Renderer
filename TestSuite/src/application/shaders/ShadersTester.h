#pragma once

#include <string>
#include "load/ShadersLoadTester.h"

class ShadersTester
{
public:
	ShadersTester();
	~ShadersTester();

	std::string test();

private:
	std::string testLoad();
};
