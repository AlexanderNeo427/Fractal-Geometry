#ifndef FRACTAL_BASE
#define FRACTAL_BASE

#include "olcPixelGameEngine.h"

/**
 * Base class for all fractal algorithms to derive from
 */
class FractalBase 
{
public:
	FractalBase(olc::PixelGameEngine* pge) 
		:
		m_pge(pge) 
	{
		m_screenWidth  = pge->ScreenWidth();
		m_screenHeight = pge->ScreenHeight();
	}

	virtual void Visualize() = 0;
protected:
	olc::PixelGameEngine* m_pge;

	int m_screenWidth;
	int m_screenHeight;
};

#endif

