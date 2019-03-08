#include "gamemanager.hpp"
#undef main

/*
The main class only starts the program. 
Need #undef main for SDL to work. 
*/

int main()
{
	GameManager app;

	app.loop();
}