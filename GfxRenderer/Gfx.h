#ifndef _GFX_H_
#define _GFX_H_

#define SDL_MAIN_HANDLED 1

#include <SDL.h>
#include <iostream>

#pragma comment(lib, "SDL2.lib")

class GfxContext
{
public:

	struct GfxColor
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;

		GfxColor()
		{
			this->r = 0;
			this->g = 0;
			this->b = 0;
			this->a = 0;
		}

		GfxColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}
	};

	//ctor
	GfxContext(const char* title, int width, int height);
	//~GfxContext();

	void Update();
	void GfxPutPixel(int x, int y, GfxColor color);
	void GfxContextBlit();
	void GfxContextClear(GfxColor color);
	int HalfWidth;
	int HalfHeight;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool IsRunning;
	unsigned long long Last;
	float DeltaTime;
	const unsigned char* KeyState;
	int Width;
	int Height;
};

#endif