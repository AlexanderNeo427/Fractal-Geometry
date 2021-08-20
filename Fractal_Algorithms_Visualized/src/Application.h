#ifndef APPLICATION_H
#define APPLICATION_H

// All scenes here
#include "Fractal Algorithms/SierpinskiTriangle.h"

class Application : public olc::PixelGameEngine
{
public:
	Application();

	bool OnUserCreate()				   override;
	bool OnUserUpdate(float deltaTime) override;
	bool OnUserDestroy()			   override;
private:
	ISimulation* m_simulation;
};

#endif