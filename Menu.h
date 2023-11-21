#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class GameWindow;

class Menu
{
private:

	bool		m_loop;

	sf::Music	*m_music;
	GameWindow	*m_window;
	sf::Sprite	*m_background;

public:

	Menu(GameWindow *window);


	void	Start();

	~Menu();

private:

	void	Display();
	void	Init();
};

