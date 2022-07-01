#pragma once

#include <string>
#include "CBufferPerObject.h"

class CBufferPerObjectColourTest
{
public:
	CBufferPerObjectColourTest();
	~CBufferPerObjectColourTest();

	std::string test();

private:
	bool success();
};
