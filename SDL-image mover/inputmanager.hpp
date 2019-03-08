#pragma once
#include <SDL.h>

class InputManager
{
public:
	enum class Direction
	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	InputManager();
	~InputManager() = default;

	void handle_events(SDL_Event const &event);
	void update(double delta_time);
	void draw(SDL_Surface *window_surface);
private:
	Direction    m_direction;

	SDL_Surface *m_image;
	SDL_Rect     m_position;
	double       m_x; // Double so that speed can be lower than 1.
	double       m_y; // --||--
};