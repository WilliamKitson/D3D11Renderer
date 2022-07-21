#pragma once

#include <string>
#include <Windows.h>
#include <d3d11.h>

#include "Output.h"
#include "Camera.h"
#include "RGBA.h"
#include "Transform.h"

namespace D3D11Renderer
{
	class Facade
	{
	public:
		Facade();
		virtual ~Facade();

		virtual void initialise(HWND, std::string);
		virtual void update();
		virtual void overlap();
		virtual void outputResolution(Output, HWND);
		virtual void syncFull();
		virtual void syncHalf();
		virtual void syncQuater();
		virtual void syncNone();
		virtual void drawWireframe();
		virtual void drawSolid();
		virtual void cullNone();
		virtual void cullFront();
		virtual void cullBack();
		virtual void sceneCamera(Camera);
		virtual void sceneAmbience(RGBA);
		virtual void objectTransform(Transform);
		virtual void objectColour(RGBA);
		virtual ID3D11Device* getDevice();
		virtual ID3D11DeviceContext* getContext();
	};
}
