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

	failures += testPos();
	failures += testFrustum();
	failures += testClipping();

	return failures;
}

std::string CameraTester::testPos()
{
	return CameraPosTester().test();
}

std::string CameraTester::testFrustum()
{
	return CameraFrustumTest().test();
}

std::string CameraTester::testClipping()
{
	return CameraClippingTest().test();
}
