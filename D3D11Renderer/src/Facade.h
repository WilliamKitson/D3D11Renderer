#pragma once

#include <string>
#include <Windows.h>
#include <d3d11.h>

#include "Output.h"

namespace D3D11Renderer
{
	class Facade
	{
	public:
		Facade();
		virtual ~Facade();

		virtual void initialise(HWND, std::string);
		virtual void update();
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
		virtual ID3D11Device* getDevice();
		virtual ID3D11DeviceContext* getContext();
	};
}
