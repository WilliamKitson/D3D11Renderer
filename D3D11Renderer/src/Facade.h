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
		virtual ID3D11DeviceContext* getContext();
		virtual void outputResolution(Output, HWND);
		virtual void syncFull();
		virtual void syncHalf();
		virtual void syncQuater();
	};
}
