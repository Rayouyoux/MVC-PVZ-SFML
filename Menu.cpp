#include "Menu.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameWindow.h"

Menu::Menu(GameWindow *window) {
	m_loop = true;

	m_window = window;

	m_background = NULL;
	m_music = NULL;
}

void	Menu::Init() {
	sf::Texture	*menuTexture = new sf::Texture();
	m_background = new sf::Sprite();

	if (!menuTexture->loadFromFile("rsrc/img/menu/background.png")) {
		std::cout << "Error loading menu.png" << std::endl;
		exit(1);
	}
	m_background->setTexture(*menuTexture);
	m_background->setOrigin(860, 540);
	m_background->setPosition(860, 540);
	m_window->Clear();
	m_window->w_window->draw(*m_background);
	m_window->w_window->display();

	m_music = new Music();
	if (!m_music->openFromFile("rsrc/music/menu/menu.ogg"))
	{
		std::cout << "Error loading menu.ogg" << std::endl;
		exit(1);
	}
	m_music->play();
	m_music->setVolume(10.0f);
	m_music->setLoop(true);
}

bool Menu::StartButton() {
	if (m_window->w_window->mapPixelToCoords(Mouse::getPosition(*m_window->w_window)).x > 0.454 * m_window->GetWidth() and \
		m_window->w_window->mapPixelToCoords(Mouse::getPosition(*m_window->w_window)).x < 0.547 * m_window->GetWidth() and \
		m_window->w_window->mapPixelToCoords(Mouse::getPosition(*m_window->w_window)).y > 0.692 * m_window->GetHeight() and \
		m_window->w_window->mapPixelToCoords(Mouse::getPosition(*m_window->w_window)).y < 0.759 * m_window->GetHeight())
		return true;
	return false;
}

bool Menu::ExitButton() {
	if (m_window->w_window->mapPixelToCoords(Mouse::getPosition(*m_window->w_window)).x > 0.626 * m_window->GetWidth() and \
		m_window->w_window->mapPixelToCoords(Mouse::getPosition(*m_window->w_window)).x < 0.713 * m_window->GetWidth() and \
		m_window->w_window->mapPixelToCoords(Mouse::getPosition(*m_window->w_window)).y > 0.704 * m_window->GetHeight() and \
		m_window->w_window->mapPixelToCoords(Mouse::getPosition(*m_window->w_window)).y < 0.756 * m_window->GetHeight())
		return true;
	return false;
}

void	Menu::Start(){
	Event	event;

	Init();
	Display();
	while (m_loop) {
		while (m_window->w_window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				m_window->Close();
			if (Mouse::isButtonPressed(Mouse::Button::Left) and m_window->w_window->hasFocus() and ExitButton())
				m_window->Close();
			else if (Mouse::isButtonPressed(Mouse::Button::Left) and m_window->w_window->hasFocus() and StartButton())
				m_loop = false;
		}
	}
	m_music->stop();
	delete m_music;
	m_window->Clear();
}

void	Menu::Display() {
	m_window->Clear();
	m_window->w_window->draw(*m_background);
	m_window->w_window->display();
}

Menu::~Menu(){
	m_music->stop();
	delete m_music;
}
