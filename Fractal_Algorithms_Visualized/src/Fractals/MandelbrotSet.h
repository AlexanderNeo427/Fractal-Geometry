#ifndef MANDELBROT_SET
#define MANDELBROT_SET

#include "olcPixelGameEngine.h"
#include "../FractalBase.h"

class MandelbrotSet : public FractalBase
{
public:
	struct Complex
	{
		float real, imaginary;

		Complex() : real(0.f), imaginary(0.f) {};
		Complex(float r, float i) : real(r), imaginary(i) {};

		float DistanceFromOrigin()
		{
			return (real * real) + (imaginary * imaginary);
		}
		float Squared()
		{
			return (real * real) - (imaginary * imaginary);
		}
	};
	struct Range
	{
		float min, max;

		Range(float _min, float _max) : min(_min), max(_max) {};
	};
public:
	static const int MAX_ITR   =  30;
	const float		 THRESHOLD =  4.f;
	const float		 R_MIN	   = -2.f;
	const float		 R_MAX	   =  0.57f;
	const float		 I_MIN	   = -1.12f;
	const float		 I_MAX	   =  1.12;
public:
	MandelbrotSet(olc::PixelGameEngine* pge) : FractalBase(pge) {};

	void Visualize() 
	{
		Range screenRangeX(0, m_screenWidth);
		Range screenRangeY(0, m_screenHeight);
		Range realRange(R_MIN, R_MAX);
		Range imaginaryRange(I_MIN, I_MAX);

		for (int y = 0; y < m_screenHeight; ++y)
		{
			for (int x = 0; x < m_screenWidth; ++x)
			{
				Complex z, c;
				c.real = RemapRange(x, screenRangeX, realRange);
				c.imaginary = RemapRange(y, screenRangeY, imaginaryRange);

				int numItr = 0;
				while (z.DistanceFromOrigin() <= THRESHOLD && numItr < MAX_ITR)
				{
					float fz = z.Squared() + c.real;
					z.imaginary = 2.f * z.real * z.imaginary + c.imaginary;
					z.real = fz;

					++numItr;
				}

				// Plotting
				if (numItr == MAX_ITR)
				{
					m_pge->Draw(x, y, olc::BLACK);
				}
				else
				{
					float colVal = static_cast<float>(numItr) / 
								   static_cast<float>(MAX_ITR);

					m_pge->Draw(x, y, olc::Pixel(colVal * 20, colVal * 255, colVal * 50));
				}
			}
		}
	}
private:
	float RemapRange(float x, Range oldRange, Range targetRange)
	{
		float t = InverseLerp(x, oldRange.min, oldRange.max);
		return Lerp(targetRange.min, targetRange.max, t);
	}
	float InverseLerp(float val, float a, float b)
	{
		return (val - a) / (b - a);
	}
	float Lerp(float a, float b, float t)
	{
		return a + (b - a) * t;
	}
};

#endif