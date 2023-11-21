#include "GameManager.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "GameWindow.h"
#include "Menu.h"
#include "Pistopois.h"

GameManager::GameManager(){
	isDone = false;
	hasWon = false;
	hasLost = false;

	window = new GameWindow();
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("rsrc/img/background.png")) {
		std::cout << "failed to load background" << std::endl;
		exit(1);
	}
	background = new sf::Sprite();
	background->setTexture(*texture);
	background->setOrigin(0.5f, 0.5f);
	//background->setPosition(960, 540);
}

void GameManager::HandleEvents() {
	Event	event;

	while (window->w_window->pollEvent(event))
	{
		window->w_window->clear();
		window->w_window->draw(*background);
		sf::Vector2i localposition = sf::Mouse::getPosition(*window->w_window);
		if (event.type == Event::Closed)
			window->Close();
		if (Mouse::isButtonPressed(Mouse::Button::Left) and window->w_window->hasFocus()) {
			Pistopois* oPistopois = new Pistopois(1);
			oPistopois->SetPosition(window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).x, window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).y);
			window->w_window->draw(*oPistopois->m_sprite);
		}
		window->w_window->display();
	}
}

void		GameManager::Start() {
	Menu	menu(window);

	menu.Start();
	while (!isDone)
	{
		HandleEvents();
	}
}

