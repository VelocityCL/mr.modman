#include "global.hpp"

#include "logger/logger.hpp"

#include "input.hpp"

void input::update()
{
	SDL_Event evt;
	while (SDL_PollEvent(&evt))
	{
		switch (evt.type)
		{
		case SDL_QUIT:
			global::shutdown = true;
			break;
		}

		ImGui_ImplSDL2_ProcessEvent(&evt);
	}
}

SDL_HitTestResult input::hit_test_callback(SDL_Window* window, const SDL_Point* p, void* data)
{
	SDL_HitTestResult report = SDL_HITTEST_NORMAL;

	if (p->y <= 20)
	{
		report = SDL_HITTEST_DRAGGABLE;
	}

	return report;
}