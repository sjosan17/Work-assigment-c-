#pragma once

#include <SDL.h>
//#include <SDL_ttf.h>
#include <iostream>
#include <memory>
#include "inputmanager.hpp"

class GameManager
{
public:
	GameManager();
	~GameManager();


	void loop();
	void update(double delta_time);
	void draw();
private:
	InputManager m_thorium_mascot;

	SDL_Window  *m_window;
	SDL_Surface *m_window_surface;
	SDL_Event    m_window_event;
};