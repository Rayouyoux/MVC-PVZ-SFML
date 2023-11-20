#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class GameWindow
{
private:

	// Main Attributes

	const char*			name;
	float				width;
	float				height;
	sf::Image*			icon;

public:

	RenderWindow		*w_window;

	GameWindow();
	~GameWindow();

	// Main Methods

	void				Clear();
	void				Close();

	// Get Methods

	float				GetWidth();
	float				GetHeight();
};

