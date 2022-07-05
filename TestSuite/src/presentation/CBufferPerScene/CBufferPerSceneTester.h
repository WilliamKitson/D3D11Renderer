#pragma once

#include <string>

#include "CBufferPerSceneWorldViewProjectionTest.h"
#include "CBufferPerSceneAmbienceTest.h"

class CBufferPerSceneTester
{
public:
	CBufferPerSceneTester();
	~CBufferPerSceneTester();

	std::string test();

private:
	std::string testWorldViewProjection();
	std::string testAmbience();
};
