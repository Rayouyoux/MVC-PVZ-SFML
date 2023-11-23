#include "Patate.h"

#include <iostream>

/*
---------------------------------------------------------------------------------
|					Here is the constructor of the patate						|
---------------------------------------------------------------------------------
*/

Patate::Patate(int id, float hp) : Plante(id) {
	SetHp(hp);
	SetSize(100, 100);
	sf::Texture* m_texture = new sf::Texture();
	if (!m_texture->loadFromFile("rsrc/img/sprite/plantes/Patate.png")) {
		std::cout << "failed to load texture" << std::endl;
		exit(1);
	}
	m_sprite = new sf::Sprite();
	SetSize(m_texture->getSize().x, m_texture->getSize().y);
	m_sprite->setTexture(*m_texture);
	m_sprite->setOrigin(GetSize().x / 2, GetSize().y / 2);
}
