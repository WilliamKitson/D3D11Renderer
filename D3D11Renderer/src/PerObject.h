#pragma once

#define _XM_NO_INTRINSICS_
#define XM_NO_ALIGNMENT

#include <d3d11.h>
#include <DirectXMath.h>

namespace D3D11Renderer
{
	class PerObject
	{
	public:
		PerObject();
		~PerObject();

		void initialise(ID3D11Device*);
		void apply(ID3D11DeviceContext*);
		void bind(ID3D11DeviceContext*);
		void setTransform(float[16]);
		void setColour(float[4]);

	private:
		void cleanup();
		void validate(IUnknown*);
		void create(ID3D11Device*);
		DirectX::XMMATRIX calculate(float[16]);

	private:
		ID3D11Buffer* cBuffer;
		float data[20];
	};
}
