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

	Menu(GameWindow *window, sf::Music *music);


	void	Start();
	int		GetVolume();

	~Menu();

private:
	
	// Main Buttons

	bool	ExitButton();
	bool	OptionButton();
	bool	StartButton();
	void	InitOptions();
	void	Options();

	// Options Buttons

	bool	OptionExitButton();
	bool	OptionMenuButton();
	bool	OptionMuteButton();


	// Display related
	void	Display();
	void	Init();
};

