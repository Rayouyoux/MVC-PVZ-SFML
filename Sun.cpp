#include "Sun.h"

#include <iostream>

/*
---------------------------------------------------------------------------------
|							Here is the constructor								|
---------------------------------------------------------------------------------
*/

Sun::Sun(float rate, float speed, float value) : GameObject() {
	m_rate = rate;
	m_speed = speed;
	m_direction.x = 0;
	m_direction.y = 1;
	m_value = value;
	SetSize(100, 100);
	sf::Texture* m_texture = new sf::Texture();
	if (!m_texture->loadFromFile("rsrc/img/sprite/sun/sun.png")) {
		std::cout << "failed to load texture" << std::endl;
		exit(1);
	}
	m_sprite = new sf::Sprite();
	SetSize(m_texture->getSize().x, m_texture->getSize().y);
	m_sprite->setTexture(*m_texture);
	m_sprite->setOrigin(GetSize().x / 2, GetSize().y / 2);
}

/*
---------------------------------------------------------------------------------
|							Here are the set methods							|
---------------------------------------------------------------------------------
*/

void Sun::SetSpeed(float s) {
	m_speed = s;
}
void Sun::SetDirection(float x, float y) {
	m_direction.x = x;
	m_direction.y = y;
}

/*
---------------------------------------------------------------------------------
|							Here are the main methods							|
---------------------------------------------------------------------------------
*/

void Sun::Move(float dt) {
	this->SetPosition(m_position.x + (m_direction.x * m_speed * dt), m_position.y + (m_direction.y * m_speed * dt));
}
