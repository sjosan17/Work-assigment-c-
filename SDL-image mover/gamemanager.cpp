#include "gamemanager.hpp"

SDL_Surface *load_surface(char const *path)
{
	SDL_Surface *image_surface = SDL_LoadBMP(path);

	if (!image_surface)
		return 0;

	return image_surface;
}
// Creating the SDL2 window, center it and provide error status
GameManager::GameManager() 
{
	/*//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return;
	}*/

	m_window = SDL_CreateWindow("App Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800, 600, 0);

	if (!m_window)
	{
		std::cout << "Failed to create window\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}

	m_window_surface = SDL_GetWindowSurface(m_window);

	if (!m_window_surface)
	{
		std::cout << "Failed to get window's surface\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}
}
// The decontructre, free up resources
GameManager::~GameManager()
{
	SDL_FreeSurface(m_window_surface);
	SDL_DestroyWindow(m_window);
	//TTF_Quit;
	SDL_Quit;
}

void GameManager::loop() // The game loop as called from main.cpp
{
	bool keep_window_open = true; // This is logic is for when user exit the program through click on "close"
	while (keep_window_open)
	{
		while (SDL_PollEvent(&m_window_event) > 0)
		{
			m_thorium_mascot.handle_events(m_window_event);
			switch (m_window_event.type)
			{
			case SDL_QUIT:
				keep_window_open = false;
				break;
			}
		}
		// Update to 60 FPS
		update(1.0 / 60.0);
		draw();
	}
}

void GameManager::update(double delta_time)
{
	m_thorium_mascot.update(delta_time);
}
// Populat the created window.
void GameManager::draw()
{
	// Fills the window with a grey background.
	SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format, 205, 205, 205));

	m_thorium_mascot.draw(m_window_surface);

	SDL_UpdateWindowSurface(m_window);
}