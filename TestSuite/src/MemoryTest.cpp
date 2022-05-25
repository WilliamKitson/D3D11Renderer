#include "MemoryTest.h"

MemoryTest::MemoryTest()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
}

MemoryTest::~MemoryTest()
{
}

std::string MemoryTest::test()
{
	if (_CrtDumpMemoryLeaks())
	{
		return "memory test failed\n";
	}

	return std::string();
}
