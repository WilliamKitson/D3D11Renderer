#pragma once

#include <string>
#include "CBufferPerScene.h"

class CBufferPerSceneWorldViewProjectionTest
{
public:
	CBufferPerSceneWorldViewProjectionTest();
	~CBufferPerSceneWorldViewProjectionTest();

	std::string test();

private:
	bool success();
};
