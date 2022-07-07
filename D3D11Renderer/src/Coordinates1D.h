#pragma once

namespace D3D11Renderer
{
	class Coordinates1D
	{
	public:
		Coordinates1D();
		~Coordinates1D();

		void push(float);
		int getCount();
		float getCoordinate();

	private:
		int count;
	};
}
