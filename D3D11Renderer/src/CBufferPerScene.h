#pragma once

namespace D3D11Renderer
{
	struct CBufferPerScene
	{
	public:
		CBufferPerScene();

	public:
		float worldViewProjection[16];
	};
}
