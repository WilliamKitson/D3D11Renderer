#pragma once

#include "Facade.h"
#include "Swapchain.h"
#include "Shaders.h"
#include "Rasteriser.h"
#include "Sampler.h"

namespace D3D11Renderer
{
	class Implimentation
		: public Facade
	{
	public:
		Implimentation();
		virtual ~Implimentation();

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

	private:
		void cleanup(IUnknown*);
		void initialise();

	private:
		ID3D11Device* device;
		ID3D11DeviceContext* context;
		Swapchain swapchain;
		Shaders shaders;
		Rasteriser rasteriser;
		Sampler sampler;
	};
}
