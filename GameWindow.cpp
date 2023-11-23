#include "GameWindow.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include  "GameObject.h"

GameWindow::GameWindow() {


	width = 1920.f;
	height = 1080.f;
	name = "Plant vs Zombies";

	//Setting up the window
	w_window = new sf::RenderWindow(sf::VideoMode((unsigned int)width, (unsigned int)height), name);
	sf::View *view = new View(sf::Vector2f(960, 540), sf::Vector2f(1920, 1080));
	w_window->setView(*view);

	//Setting up the icon

	icon = new sf::Image();
	if (!icon->loadFromFile("rsrc/img/icon/icon.png"))
	{
		std::cout << "Error loading icon" << std::endl;
		exit(1);
	}
	w_window->setIcon(icon->getSize().x, icon->getSize().y, icon->getPixelsPtr());
}

/*
---------------------------------------------------------------------------------
|				Here are all the get methods									|
---------------------------------------------------------------------------------
*/

float GameWindow::GetWidth() {
	return (float)width;
}

float GameWindow::GetHeight() {
	return (float)height;
}

/*
---------------------------------------------------------------------------------
|				Here are all the main methods									|
---------------------------------------------------------------------------------
*/

void	GameWindow::DrawObject(GameObject *object) {
	w_window->draw(*object->m_sprite);
}

void	GameWindow::Display() {
	w_window->display();
}

void	GameWindow::Clear() {
	w_window->clear();
}

void	GameWindow::Close() {
	w_window->close();
	exit(0);
}

GameWindow::~GameWindow() {
	delete icon;
	delete w_window;
}