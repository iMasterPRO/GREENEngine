#include "Game.h"



namespace core
{
	Game::Game(const char* title, int width, int height)
	{
		m_title = title;
		m_width = width;
		m_height = height;

		isRunning = true;

		window = NULL;
	}

	Game::~Game()
	{
		delete window;
	}

	void Game::run() 
	{
		init();
		loop();
	}

	void Game::init() 
	{
		window = new graphics::Window(m_title, m_width, m_height);
		window->init();
	}

	void Game::loop() 
	{
		while (isRunning) 
		{
			loopInit();
			input();
			draw();
		}
	}

	void Game::loopInit() 
	{
	}

	void Game::input() 
	{
		while(SDL_PollEvent(&e)) 
		{
			if (e.type == SDL_QUIT)
				isRunning = false;

			if (e.type == SDL_KEYDOWN) 
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
					isRunning = false;
			}
		}
	}

	void Game::draw() 
	{
		glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		////////////////////////////////////////////////////

		///////////////////////////////////////////////////
		window->swap();
	}
}
