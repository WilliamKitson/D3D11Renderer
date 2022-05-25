#include "ResolutionDefaultWidthTest.h"

ResolutionDefaultWidthTest::ResolutionDefaultWidthTest()
{
}

ResolutionDefaultWidthTest::~ResolutionDefaultWidthTest()
{
}

std::string ResolutionDefaultWidthTest::test()
{
	if (windowsPlatform::Resolution().getWidth() == 960)
	{
		return std::string();
	}

	return "resolution default width test failed\n";
}
