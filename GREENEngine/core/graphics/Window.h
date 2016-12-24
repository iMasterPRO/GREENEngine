#pragma once

#include <iostream>
#include "SDL2\SDL.h"
#include "GL\glew.h"

using namespace std;

namespace core {
	namespace graphics
	{
		class Window
		{
		public:
			Window(const char* title, int width, int height);
			~Window();
			
			void init();
			void swap();

		private:
			const char* m_title;
			int m_width;
			int m_height;

			SDL_Window* window;
			SDL_GLContext context;
		};
	}
}

