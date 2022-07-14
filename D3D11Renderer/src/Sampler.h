#pragma once

#include <d3d11.h>

namespace D3D11Renderer
{
	class Sampler
	{
	public:
		Sampler();
		~Sampler();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);

	private:
		void validate(IUnknown*);

	private:
		ID3D11SamplerState* state;
		D3D11_SAMPLER_DESC description;
	};
}
