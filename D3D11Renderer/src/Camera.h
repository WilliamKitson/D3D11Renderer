#pragma once

namespace D3D11Renderer
{
	struct Camera
	{
	public:
		const float xpos{ 0.0f };
		const float ypos{ 0.0f };
		const float zpos{ 0.0f };
		const float xrot{ 0.0f };
		const float yrot{ 0.0f };
		const float zrot{ 0.0f };
		const float frustum{ 0.0f };
		const float aspectRatio{ 0.0f };
	};
}
