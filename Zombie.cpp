#include "Zombie.h"

#include <iostream>

Zombie::Zombie() : GameObject() {
	m_Speed = 300;
	m_Hp = 50;
	m_HpMax = 50;
	m_Damage = 50;
	m_vDirection;
	m_vDirection.push_back(-1);
	
	sf::Texture* m_texture = new sf::Texture();
	if (!m_texture->loadFromFile("rsrc/img/sprite/zombies/Zombie.png")) {
		std::cout << "failed to load texture" << std::endl;
		exit(1);
	}
	m_sprite = new sf::Sprite();
	SetSize(m_texture->getSize().x, m_texture->getSize().y);
	m_sprite->setTexture(*m_texture);
	m_sprite->setOrigin(GetSize().x / 2, GetSize().y / 2);
}

void Zombie::move(float fDeltaTime) {
	m_position.x -= 10 * fDeltaTime * m_Speed;
	SetPosition(m_position.x, m_position.y);
}