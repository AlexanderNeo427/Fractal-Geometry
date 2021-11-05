#ifndef APPLICATION
#define APPLICATION

#include "olcPixelGameEngine.h"
#include "Fractal Algorithms/SierpinskiTriangle.h"

class Application : public olc::PixelGameEngine
{
public:
	Application()
	{
		sAppName = "olcPixelGameEngine - Fractal Algorithms Visualized";
	}

	bool OnUserCreate()
	{
		m_fractalBase = new SierpinskiTriangle(this);
		m_fractalBase->Visualize();

		return true;
	}
	bool OnUserUpdate(float deltaTime) { return true; }
private:
	FractalBase* m_fractalBase;
};

#endif
