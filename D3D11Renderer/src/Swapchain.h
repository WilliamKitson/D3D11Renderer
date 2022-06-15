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
		void initialiseState(ID3D11Device*, HWND);
		IDXGIFactory* getFactory(ID3D11Device*);
		IDXGIAdapter* getAdapter(ID3D11Device*);
		IDXGIDevice* getDevice(ID3D11Device*);
		DXGI_SWAP_CHAIN_DESC getDescription(HWND);
		void initialiseView(ID3D11Device*);
		ID3D11Texture2D* getBackBuffer();
		void bindRenderTargets(ID3D11DeviceContext*);
		void bindViewport(ID3D11DeviceContext*);

	private:
		Resolution resolution;
		IDXGISwapChain* state;
		ID3D11RenderTargetView* view;
		ID3D11DepthStencilView* depth;
	};
}
