#include "GameManager.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "GameWindow.h"
#include "Menu.h"
#include "Pistopois.h"
#include "Zombie.h"

GameManager::GameManager(){
	isDone = false;
	hasWon = false;
	hasLost = false;
	fDeltaTime = 0;
	window = new GameWindow();
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("rsrc/img/background.png")) {
		std::cout << "failed to load background" << std::endl;
		exit(1);
	}
	background = new sf::Sprite();
	background->setTexture(*texture);
	background->setOrigin(860, 540);
	background->setPosition(860, 540);
	
}

void GameManager::HandleEvents() {
	Zombie* oZombie = new Zombie();
	oZombie->SetPosition(1020, 800);
	Event	event;
	sf::Clock oClock;
	
	while (true) {
		
		while (window->w_window->pollEvent(event))
		{
			window->w_window->clear();
			window->w_window->draw(*background);

			oZombie->move(fDeltaTime);
			window->w_window->draw(*oZombie->m_sprite);
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
		LimitFps(fDeltaTime);
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

void GameManager::LimitFps(float fps) {
	sf::Clock oClock;
	fDeltaTime = oClock.restart().asSeconds();
	//if (g_deltaTime < g_fpsLimit) {
	//	sleep(seconds(g_fpsLimit - g_deltaTime));
	//	g_deltaTime += g_fpsLimit - g_deltaTime;
	//}
}

GameManager::~GameManager() {
	
}

