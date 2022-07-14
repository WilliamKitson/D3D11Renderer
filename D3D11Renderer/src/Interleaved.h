#pragma once

#include <d3d11.h>
#include "Coordinates1D.h"

namespace D3D11Renderer
{
	class Interleaved
	{
	public:
		Interleaved();
		~Interleaved();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);
		void pushVertex(float[8]);

	private:
		void cleanup();
		void validate();
		void create(ID3D11Device*);

	private:
		ID3D11Buffer* vBuffer;
		Coordinates1D data;
	};
}
