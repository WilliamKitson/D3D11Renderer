#pragma once

#include <string>
#include <Windows.h>
#include <d3d11.h>

namespace D3D11Renderer
{
	class Facade
	{
	public:
		Facade();
		virtual ~Facade();

		virtual void initialise(HWND, std::string);
		virtual ID3D11DeviceContext* getContext();
	};
}
