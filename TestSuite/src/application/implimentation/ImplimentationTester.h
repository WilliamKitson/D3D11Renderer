#pragma once

#include <string>

#include "resolution/ImplimentationResolutionTester.h"
#include "sync/ImplimentationSyncTester.h"
#include "draw/ImplimentationDrawTester.h"
#include "cull/ImplimentationCullTester.h"
#include "scene/ImplimentationSceneTester.h"
#include "object/ImplimentationObjectTester.h"
#include "ImplimentationDeviceTest.h"
#include "ImplimentationShadersTest.h"
#include "ImplimentationSamplerTest.h"

class ImplimentationTester
{
public:
	ImplimentationTester(HINSTANCE, int);
	~ImplimentationTester();

	std::string test();

private:
	std::string testResolution();
	std::string testSync();
	std::string testDraw();
	std::string testCull();
	std::string testScene();
	std::string testObject();
	std::string testDevice();
	std::string testShaders();
	std::string testSampler();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
