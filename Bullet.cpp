#include "Bullet.h"
#include <iostream>

Bullet::Bullet(float posx, float posy) {
	m_position.x = posx;
	m_position.y = posy;
	m_speed = 500.f;
	m_direction.x = 1;
	m_direction.y = 0;
	sf::Texture* m_texture = new sf::Texture();
	if (!m_texture->loadFromFile("rsrc/img/sprite/plantes/bullet.png")) {
		std::cout << "failed to load texture" << std::endl;
		exit(1);
	}
	m_sprite = new sf::Sprite();
	SetSize(m_texture->getSize().x, m_texture->getSize().y);
	m_sprite->setTexture(*m_texture);
	m_sprite->setOrigin(GetSize().x / 2, GetSize().y / 2);
}

void Bullet::SetSpeed(float s) {
	m_speed = s;
}

void Bullet::SetDirection(float x, float y) {
	m_direction.x = x;
	m_direction.y = y;
}

void Bullet::Move(float dt) {
	this->SetPosition(m_position.x + (m_direction.x * m_speed * dt), m_position.y + (m_direction.y * m_speed * dt));
}