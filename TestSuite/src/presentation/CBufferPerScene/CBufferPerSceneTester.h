#pragma once

#include <string>
#include "CBufferPerSceneWorldViewProjectionTest.h"

class CBufferPerSceneTester
{
public:
	CBufferPerSceneTester();
	~CBufferPerSceneTester();

	std::string test();

private:
	std::string testWorldViewProjection();
};
