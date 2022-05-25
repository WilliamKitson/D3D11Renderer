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
	failures += testYpos();

	return failures;
}

std::string CameraTester::testXpos()
{
	return CameraXposTest().test();
}

std::string CameraTester::testYpos()
{
	return CameraYposTest().test();
}
