#pragma once

#include <d3d11.h>

namespace D3D11Renderer
{
	class Interleaved
	{
	public:
		Interleaved();
		~Interleaved();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);
	};
}
