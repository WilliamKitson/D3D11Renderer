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
		void setIndex(int);

	private:
		void cleanup();
		void increment();
		void swap(float*);
		float* pushed();

	private:
		int count;
		int index;
		float* coordinates;
	};
}
