#define OLC_PGE_APPLICATION

#include "../lib/olcPixelGameEngine.h"

// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		// Name your application
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		return true;
	}
};

int main()
{
	Example demo;

	if (demo.Construct(800, 800, 1, 1, false, true, false))
		demo.Start();

	return 0;
}