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
	SierpinskiTriangle(olc::PixelGameEngine* pge) : FractalBase(pge) {};

	void Visualize()
	{
		m_pge->Clear(olc::BLACK);

		static const float offset = 8.f;

		glm::vec2 top = glm::vec2(m_screenWidth * 0.5f, offset);
		glm::vec2 botLeft = glm::vec2(offset, m_screenHeight - offset);
		glm::vec2 botRight = glm::vec2(m_screenWidth - offset, m_screenHeight - offset);

		DrawSierpinski(0, top, botLeft, botRight);
	}
private:
	void DrawSierpinski(const int		 lvl,
						const glm::vec2& p1,
						const glm::vec2& p2,
						const glm::vec2& p3)
	{
		if (lvl >= MAX_LVL)
		{
			m_pge->DrawTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, olc::RED);
			return;
		}
		else
		{
			glm::vec2 dirUpRight = glm::normalize(p1 - p2);
			glm::vec2 dirDownLeft = -dirUpRight;
			glm::vec2 dirUpLeft = glm::normalize(p1 - p3);
			glm::vec2 dirDownRight = -dirUpLeft;

			float halfLength = glm::distance(p1, p2) * 0.5f;
			float halfWidth = std::fabs(p1.y - p2.y) * 0.5f;

			DrawSierpinski(lvl + 1,
						   p1,
						   p1 + dirDownLeft * halfLength,
						   p1 + dirDownRight * halfLength);

			DrawSierpinski(lvl + 1,
						   p2 + dirUpRight * halfLength,
						   p2,
						   (p2 + dirUpRight * halfLength) + dirDownRight * halfLength);

			DrawSierpinski(lvl + 1,
						   p3 + dirUpLeft * halfLength,
						   (p3 + dirUpLeft * halfLength) + dirDownLeft * halfLength,
						   p3);
		}
	}
};

#endif
