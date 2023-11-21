#pragma once

#include <SFML/Audio.hpp>

class GameWindow;

class Menu
{
private:

	bool		m_loop;

	//sf::Music*	m_music;
	GameWindow* m_window;

public:

	Menu(GameWindow *window);


	void	Start();

	~Menu();

private:

	void	Display();
};

