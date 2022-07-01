#pragma once

#include <string>
#include "CBufferPerObject.h"

class CBufferPerObjectTransformTest
{
public:
	CBufferPerObjectTransformTest();
	~CBufferPerObjectTransformTest();

	std::string test();

private:
	bool success();
};
