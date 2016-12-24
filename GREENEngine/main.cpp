#include <iostream>
#include "core\Game.h"
#undef main //THERE IS THE SAME int main(void) METHOD DECLARED IN SDL2 LIBRARY

#define TITLE "GREENEngine | BETA 0.0.1"
#define WIDTH 1080
#define HEIGHT 720

using namespace std;

int main() 
{
	core::Game game(TITLE, WIDTH, HEIGHT);
	game.run();

	return EXIT_SUCCESS;
}
