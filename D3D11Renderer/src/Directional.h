#pragma once

#include <d3d11.h>

namespace D3D11Renderer
{
	class Directional
	{
	public:
		Directional();
		~Directional();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);

	private:
		ID3D11Buffer* cBuffer;
		float data[8];
	};
}
