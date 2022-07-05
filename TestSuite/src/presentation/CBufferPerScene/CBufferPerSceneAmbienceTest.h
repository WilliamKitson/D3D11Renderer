#pragma once

#include <string>
#include "CBufferPerScene.h"

class CBufferPerSceneAmbienceTest
{
public:
	CBufferPerSceneAmbienceTest();
	~CBufferPerSceneAmbienceTest();

	std::string test();

private:
	bool success();
};
