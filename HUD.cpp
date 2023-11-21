#include <SFML/Graphics.hpp>
#include <iostream>

#include "Hud.h"

#include "GameWindow.h"

Hud::Hud(GameWindow* window) {

	m_window = window;

	if (!m_font.loadFromFile("rsrc/font/font.ttf"))
	{
		std::cout << "Error Loading font" << std::endl;
		exit(1);
	}
	m_money.setFont(m_font);
	m_money.setCharacterSize(35);
	m_money.setFillColor(sf::Color::White);
	m_money.setStyle(sf::Text::Bold);
	m_money.setPosition(50, 0);

	m_moneytexture = new sf::Texture();
	m_moneyIcon = new sf::Sprite();

	if (!m_moneytexture->loadFromFile("rsrc/img/hud/money.png"))
	{
		std::cout << "Error loading money.png" << std::endl;
		exit(1);
	}
	m_moneyIcon->setTexture(*m_moneytexture);
	m_moneyIcon->setPosition(0, 0);

	m_playtexture = new sf::Texture();
	m_playIcon = new sf::Sprite();

	if (!m_playtexture->loadFromFile("rsrc/img/hud/play.png"))
	{
		std::cout << "Error loading play.png" << std::endl;
		exit(1);
	}
	m_playIcon->setTexture(*m_playtexture);
	m_playIcon->setPosition(window->GetWidth() - 250, window->GetHeight() / 2 - 100);
}

void	Hud::DrawHud(int money, int zombienum) {
	m_window->w_window->draw(*m_moneyIcon);
	m_window->w_window->draw(*m_playIcon);
	m_money.setString(std::to_string(money));
	m_window->w_window->draw(m_money);
}
