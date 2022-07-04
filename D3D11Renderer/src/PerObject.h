#pragma once

#include <d3d11.h>
#include "CBufferPerObject.h"

namespace D3D11Renderer
{
	class PerObject
	{
	public:
		PerObject();
		~PerObject();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);
		void setTransform(float[16]);

	private:
		void cleanup();

	private:
		ID3D11Buffer* cBuffer;
		CBufferPerObject data;
	};
}
