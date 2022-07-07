#pragma once

namespace D3D11Renderer
{
	class Coordinates3D
	{
	public:
		Coordinates3D();
		~Coordinates3D();

		void push(float[3]);
		void clear();
		int getCount();
		float getX();
		float getY();
		float getZ();
		void setIndex(int);

	private:
		void cleanup();
		void swap(float*);
		float* pushed();
		void incriment();
		void xInitialise(float);
		void yInitialise(float);
		void zInitialise(float);
		void validate();
		int xIndex();
		int yIndex();
		int zIndex();
		int minimum(int);
		int maximum(int);

	private:
		int count;
		int index;
		float* coordinates;
	};
}
