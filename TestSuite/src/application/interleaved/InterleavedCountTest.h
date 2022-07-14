#pragma once

#include <string>
#include "Interleaved.h"

class InterleavedCountTest
{
public:
	InterleavedCountTest();
	~InterleavedCountTest();

	std::string test();

private:
	int itterations;
	int successes;
};
