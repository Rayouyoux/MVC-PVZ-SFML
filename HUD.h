#pragma once

#include <SFML/Graphics.hpp>

class GameWindow;

class Hud
{
private:

	// Main Attributes
	sf::Font					m_font;
	GameWindow*					m_window;

	sf::Texture*				m_moneytexture;
	sf::Sprite*					m_moneyIcon;
	sf::Text					m_money;

	sf::Texture*				m_playtexture;
	sf::Sprite*					m_playIcon;

	sf::Texture*				m_choosetexture;
	sf::Sprite*					m_choose;

public:

	

	Hud(GameWindow* window);

	//Main Methods

	void	DrawHud(int money, int zombienum, bool isPlaying);
};


