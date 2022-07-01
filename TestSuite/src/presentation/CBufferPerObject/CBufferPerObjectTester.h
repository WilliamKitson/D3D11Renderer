#pragma once

#include <string>

#include "CBufferPerObjectTransformTest.h"
#include "CBufferPerObjectColourTest.h"

class CBufferPerObjectTester
{
public:
	CBufferPerObjectTester();
	~CBufferPerObjectTester();

	std::string test();

private:
	std::string testTransfrom();
	std::string testColour();
};
