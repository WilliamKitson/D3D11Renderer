#pragma once

#include <d3d11.h>

namespace D3D11Renderer
{
	class Rasteriser
	{
	public:
		Rasteriser();
		~Rasteriser();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);

	private:
		ID3D11RasterizerState* rasteriser;
	};
}
