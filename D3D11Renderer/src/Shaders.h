#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#include <string>
#include <codecvt>

namespace D3D11Renderer
{
	class Shaders
	{
	public:
		Shaders();
		~Shaders();

		void initialise(ID3D11Device*);
		void bind(ID3D11DeviceContext*);

	private:
		ID3D11VertexShader* vShader;
	};
}
