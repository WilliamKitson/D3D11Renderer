#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT

#include <d3d11.h>
#include <DirectXMath.h>

namespace D3D11Renderer
{
	class PerScene
	{
	public:
		PerScene();
		~PerScene();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);
		void setCamera(float[8]);

	private:
		void camera();
		void ambience();
		void cleanup();
		DirectX::XMMATRIX worldViewProjection(float[8]);

	private:
		ID3D11Buffer* cBuffer;
		float data[20];
	};
}
