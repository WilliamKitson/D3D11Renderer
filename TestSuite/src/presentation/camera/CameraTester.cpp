#include "CameraTester.h"

CameraTester::CameraTester()
{
}

CameraTester::~CameraTester()
{
}

std::string CameraTester::test()
{
	std::string output{ "" };

	output += testPos();
	output += testRot();
	output += testFrustum();
	output += testClipping();

	return output;
}

std::string CameraTester::testPos()
{
	return CameraPosTester().test();
}

std::string CameraTester::testRot()
{
	return CameraRotTester().test();
}

std::string CameraTester::testFrustum()
{
	return CameraFrustumTest().test();
}

std::string CameraTester::testClipping()
{
	return CameraClippingTest().test();
}
