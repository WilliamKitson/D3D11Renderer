#pragma once

#include <d3d11.h>
#include "Coordinates1D.h"

namespace D3D11Renderer
{
	class Geometry
	{
	public:
		Geometry();
		~Geometry();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);
		void pushPosition(float[3]);

	private:
		ID3D11Buffer* vBuffers[3];
		Coordinates1D data[3];
	};
}
