#include "SierpinskiTriangle.h"

SierpinskiTriangle::SierpinskiTriangle()
	:
	m_firstRun(true)
{
}

void SierpinskiTriangle::Init()
{
}

void SierpinskiTriangle::Update(float deltaTime)
{
}

void SierpinskiTriangle::Render(olc::PixelGameEngine* pge)
{
	if (!m_firstRun) return;

	pge->Clear(olc::BLACK);

	int scrWidth = pge->ScreenWidth();
	int scrHeight = pge->ScreenHeight();
	static const float offset = 8.f;

	glm::vec2 top	   = glm::vec2(scrWidth * 0.5f, offset);
	glm::vec2 botLeft  = glm::vec2(offset, scrHeight - offset);
	glm::vec2 botRight = glm::vec2(scrWidth - offset, scrHeight - offset);

	DrawSierpinski(pge, 0, top, botLeft, botRight);

	m_firstRun = false;
}

void SierpinskiTriangle::Exit()
{
}

void SierpinskiTriangle::DrawSierpinski(olc::PixelGameEngine* pge, 
										int					  lvl, 
										const glm::vec2&	  p1,
										const glm::vec2&	  p2,
										const glm::vec2&	  p3)
{
	if (lvl >= MAX_LVL)
	{
		pge->DrawTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, olc::RED);
		return;
	}
	else
	{
		glm::vec2 dirUpRight   = glm::normalize(p1 - p2);
		glm::vec2 dirDownLeft  = -dirUpRight;
		glm::vec2 dirUpLeft	   = glm::normalize(p1 - p3);
		glm::vec2 dirDownRight = -dirUpLeft;

		float halfLength = glm::distance(p1, p2) * 0.5f;
		float halfWidth = std::fabs(p1.y - p2.y) * 0.5f;

		DrawSierpinski(pge, lvl + 1, 
					   p1, 
					   p1 + dirDownLeft * halfLength,
					   p1 + dirDownRight * halfLength);

		DrawSierpinski(pge, lvl + 1, 
					   p2 + dirUpRight * halfLength,
					   p2,
					  (p2 + dirUpRight * halfLength) + dirDownRight * halfLength);

		DrawSierpinski(pge, lvl + 1,
					   p3 + dirUpLeft * halfLength,
					  (p3 + dirUpLeft * halfLength) + dirDownLeft * halfLength,
					   p3);
	}
}
