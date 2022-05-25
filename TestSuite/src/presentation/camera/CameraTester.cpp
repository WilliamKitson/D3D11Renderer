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
	failures += testZpos();
	failures += testFrustum();

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

std::string CameraTester::testZpos()
{
	return CameraZposTest().test();
}

std::string CameraTester::testFrustum()
{
	return CameraFrustumTest().test();
}
