#ifndef APPLICATION
#define APPLICATION

#include "olcPixelGameEngine.h"

#include "Fractals/SierpinskiTriangle.h"
#include "Fractals/MandelbrotSet.h"

class Application : public olc::PixelGameEngine
{
public:
	Application()
	{
		sAppName = "olcPixelGameEngine - Fractal Algorithms Visualized";
	}

	~Application()
	{
		delete m_fractalBase;
	}

	bool OnUserCreate()
	{
		m_fractalBase = new MandelbrotSet(this);
		m_fractalBase->Visualize();

		return true;
	}
	bool OnUserUpdate(float deltaTime) { return true; }
private:
	FractalBase* m_fractalBase;
};

#endif
