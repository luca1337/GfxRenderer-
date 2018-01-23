#include "Gfx.h"

GfxContext::GfxContext(const char* title, int width, int height)
{
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);

	if (SDL_CreateWindowAndRenderer(width, height, 0, &this->window, &this->renderer))
		std::cout << "there was an error while creating\nContext or Renderer." << SDL_GetError() << std::endl;

	SDL_SetWindowTitle(this->window, title);

	this->IsRunning = true;
	this->DeltaTime = 0.0f;
	this->Last = SDL_GetPerformanceCounter();
	this->KeyState = SDL_GetKeyboardState(NULL);
	this->Width = width;
	this->Height = height;
	this->HalfWidth = width / 2;
	this->HalfHeight = height / 2;
}

void GfxContext::GfxPutPixel(int x, int y, GfxContext::GfxColor color)
{
	SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(this->renderer, x, y);
}

void GfxContext::GfxContextBlit()
{
	SDL_RenderPresent(this->renderer);
	unsigned long long now = SDL_GetPerformanceCounter();
	this->DeltaTime = (float)(now - this->Last) / SDL_GetPerformanceFrequency();
	this->Last = now;
}

void GfxContext::GfxContextClear(GfxContext::GfxColor color)
{
	SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(this->renderer);
}

void GfxContext::Update()
{
	GfxColor red = GfxColor(255, 0, 0, 255);

	while (this->IsRunning)
	{
		SDL_PumpEvents();

		GfxContextClear(red);

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				this->GfxPutPixel(i, j, GfxColor{ 0, 255, 0, 255 });
			}
		}

		GfxContextBlit();
	}
}
