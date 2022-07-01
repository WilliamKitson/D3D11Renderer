#pragma once

namespace D3D11Renderer
{
	struct CBufferPerObject
	{
	public:
		CBufferPerObject();

	public:
		float transform[16];
		float colour[4];

	private:
		void initTransform();
		void initColour();
	};
}
