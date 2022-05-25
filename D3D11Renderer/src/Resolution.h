#pragma once

namespace D3D11Renderer
{
	class Resolution
	{
	public:
		Resolution();
		~Resolution();

		int getWidth();
		int getHeight();
		void setResolution(int[2]);

	private:
		int validateMinimum(int, int);

	private:
		int resolution[2];
	};
}
