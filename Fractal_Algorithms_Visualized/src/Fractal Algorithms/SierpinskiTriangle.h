#ifndef SIERPINSKI_TRIANGLE
#define SIERPINSKI_TRIANGLE

#include "../FractalBase.h"
#include "glm/common.hpp"
#include "glm/glm.hpp"
#include "glm/vec2.hpp"

class SierpinskiTriangle : public FractalBase
{
public:
	static const int MAX_LVL = 6; // Recursion depth
public:
	SierpinskiTriangle(olc::PixelGameEngine* pge);

	void Visualize() override;
private:
	void DrawSierpinski(const int		 lvl,
						const glm::vec2& p1,
						const glm::vec2& p2,
						const glm::vec2& p3);
};

#endif
