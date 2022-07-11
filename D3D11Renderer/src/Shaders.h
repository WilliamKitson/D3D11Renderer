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
		void setFilepath(std::string);

	private:
		void cleanup(IUnknown*);
		void validate(IUnknown*);
		void vLoad(ID3D11Device*);
		void pLoad(ID3D11Device*);

	private:
		ID3D11VertexShader* vShader;
		ID3D11PixelShader* pShader;
		std::wstring filepath;
	};
}
