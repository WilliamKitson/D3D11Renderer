#include "CameraTester.h"

CameraTester::CameraTester()
{
}

CameraTester::~CameraTester()
{
}

std::string CameraTester::test()
{
	std::string failures{ "" };

	failures += testXpos();

	return failures;
}

std::string CameraTester::testXpos()
{
	return CameraXposTest().test();
}
