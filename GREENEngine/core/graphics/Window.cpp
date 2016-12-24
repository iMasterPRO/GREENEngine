#include "Window.h"



namespace core
{
	namespace graphics
	{
		Window::Window(const char* title, int width, int height)
		{
			m_title = title;
			m_width = width;
			m_height = height;

			window = NULL;
			context = NULL;
		}

		Window::~Window()
		{
			SDL_GL_DeleteContext(context);
			SDL_DestroyWindow(window);
		}

		void Window::init() 
		{
			//OpenGL ATTRIBUTES
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

			//WINDOW CREATION
			window = SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
			context = SDL_GL_CreateContext(window);
			glEnable(GL_DEPTH);
			glViewport(0, 0, m_width, m_height);

			//GLEW INITIALIZATION
			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK) 
			{
				cout << "ERROR: GLEW initialization failed" << endl;
			}
		}

		void Window::swap()
		{
			SDL_GL_SwapWindow(window);
		}
	}
}
