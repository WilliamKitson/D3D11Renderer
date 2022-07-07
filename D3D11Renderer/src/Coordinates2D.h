#pragma once

namespace D3D11Renderer
{
	class Coordinates2D
	{
	public:
		Coordinates2D();
		~Coordinates2D();

		void push(float[2]);
		void clear();
		int getCount();
		float getX();
		float getY();
		void setIndex(int);

	private:
		void cleanup();
		void swap(float*);
		float* pushed();
		void incriment();
		void xInitialise(float);
		void yInitialise(float);
		void validate();
		int xIndex();
		int yIndex();
		int minimum(int);
		int maximum(int);

	private:
		int count;
		int index;
		float* coordinates;
	};
}
