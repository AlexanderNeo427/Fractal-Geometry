#ifndef SIERPINSKI_TRIANGLE
#define SIERPINSKI_TRIANGLE

#include "../ISimulation.h"

#include "glm/common.hpp"
#include "glm/glm.hpp"
#include "glm/vec2.hpp"

class SierpinskiTriangle : public ISimulation
{
public:
	const int MAX_LVL = 6;
public:
	SierpinskiTriangle();

	void Init()							   override;
	void Update(float deltaTime)		   override;
	void Render(olc::PixelGameEngine* pge) override;
	void Exit()							   override;
private:
	void DrawSierpinski(olc::PixelGameEngine* pge, 
						int					  lvl,
						const glm::vec2&	  p1,
						const glm::vec2&	  p2,
						const glm::vec2&	  p3);
private:
	bool m_firstRun;
};

#endif
