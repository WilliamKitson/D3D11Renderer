#pragma once

#include "Facade.h"
#include "Swapchain.h"

namespace D3D11Renderer
{
	class Implimentation
		: public Facade
	{
	public:
		Implimentation();
		virtual ~Implimentation();

		virtual void initialise(HWND, std::string);
		virtual ID3D11DeviceContext* getContext();
		virtual void outputResolution(Output, HWND);

	private:
		void cleanup(IUnknown*);
		void initialise();

	private:
		ID3D11Device* device;
		ID3D11DeviceContext* context;
		Swapchain swapchain;
	};
}
