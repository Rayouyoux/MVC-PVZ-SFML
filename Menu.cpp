#include "Menu.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameWindow.h"

Menu::Menu(GameWindow *window) {
	m_loop = true;

	m_window = window;
	//if (!m_music->openFromFile("rsrc/music/menu/menu.ogg"))
	//{
	//	std::cout << "Error loading menu.ogg" << std::endl;
	//	exit(1);
	//}
	//m_music->play();
	//m_music->setVolume(10.0f);
	//m_music->setLoop(true);
}

void	Menu::Start(){
	Event	event;

	Display();
	while (m_loop) {
		while (m_window->w_window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				m_window->Close();
			if (Mouse::isButtonPressed(Mouse::Button::Left) and m_window->w_window->hasFocus())
				m_loop = false;
				
		}
		//ChooseLevel();
	}

	m_window->Clear();
}

void	Menu::Display() {
	sf::Texture	menuTexture;
	sf::Sprite	menu;

	if (!menuTexture.loadFromFile("rsrc/img/menu.png")) {
		std::cout << "Error loading menu.png" << std::endl;
		exit(1);
	}
	menu.setTexture(menuTexture);
	m_window->Clear();
	m_window->w_window->draw(menu);
	m_window->w_window->display();
}

Menu::~Menu(){
	//m_music->stop();
	//delete m_music;
}
