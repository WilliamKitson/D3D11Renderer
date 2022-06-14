#pragma once

#include <d3d11.h>
#include "Resolution.h"

namespace D3D11Renderer
{
	class Swapchain
	{
	public:
		Swapchain();
		~Swapchain();

		void initialise(ID3D11Device*, HWND);
		void bind(ID3D11DeviceContext*);

	private:
		Resolution resolution;
		D3D11_VIEWPORT viewport;
	};
}
