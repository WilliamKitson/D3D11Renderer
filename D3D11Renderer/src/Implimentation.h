#pragma once

#include "Facade.h"
#include "Swapchain.h"
#include "Shaders.h"
#include "Rasteriser.h"
#include "Sampler.h"
#include "PerScene.h"
#include "PerObject.h"

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
		virtual void sceneAmbience(RGB);
		virtual void objectTransform(Transform);
		virtual void objectColour(RGB);
		virtual ID3D11Device* getDevice();
		virtual ID3D11DeviceContext* getContext();

	private:
		void cleanup(IUnknown*);
		void initialiseDevice();
		void initialiseSwapchain(HWND);
		void initialiseShaders(std::string);
		void initialiseRasteriser();
		void initialiseSampler();
		void initialiseScene();
		void initialiseObject();

	private:
		ID3D11Device* device;
		ID3D11DeviceContext* context;
		Swapchain swapchain;
		Shaders shaders;
		Rasteriser rasteriser;
		Sampler sampler;
		PerScene scene;
		PerObject object;
	};
}
