#include "Gfx.h"

int main()
{
	GfxContext* context = new GfxContext("GfxTest", 800, 600);

	context->Update();

	return 0;
}