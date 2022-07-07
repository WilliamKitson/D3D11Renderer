#pragma once

#include <d3d11.h>

namespace D3D11Renderer
{
	class Geometry
	{
	public:
		Geometry();
		~Geometry();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);
	};
}
