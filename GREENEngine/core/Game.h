#pragma once

#include <iostream>
#include "SDL2\SDL.h"
#include "GL\glew.h"
#include "graphics\Window.h"

namespace core
{
	class Game
	{
	public:
		Game(const char* title, int width, int height);
		~Game();

		void run();

	private:
		const char* m_title;
		int m_width;
		int m_height;

		void init();
		void loop();

		void loopInit();
		void input();
		void draw();

		SDL_Event e;

		bool isRunning;

		graphics::Window* window;
	};
}

