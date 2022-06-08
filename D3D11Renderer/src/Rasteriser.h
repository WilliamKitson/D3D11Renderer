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
		void setWireframe();
		void setSolid();
		void setNone();
		void setFront();

	private:
		D3D11_RASTERIZER_DESC description;
		ID3D11RasterizerState* rasteriser;
	};
}
