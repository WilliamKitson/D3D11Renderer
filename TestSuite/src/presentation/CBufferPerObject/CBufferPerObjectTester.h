#pragma once

#include <string>
#include "CBufferPerObjectTransformTest.h"

class CBufferPerObjectTester
{
public:
	CBufferPerObjectTester();
	~CBufferPerObjectTester();

	std::string test();

private:
	std::string testTransfrom();
};
