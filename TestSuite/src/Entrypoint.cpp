#include <iostream>

#include "SubordinateTester.h"
#include "MemoryTest.h"

int main()
{
	std::cout << SubordinateTester().test() << MemoryTest().test();
	return 0;
}
