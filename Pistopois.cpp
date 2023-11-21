#include "Pistopois.h"
#include <iostream>


Pistopois::Pistopois(int id) : Plante(id) {
	m_rate = 10.f;
	m_damage = 10.f;
	sf::Texture* m_texture = new sf::Texture();
	if (!m_texture->loadFromFile("rsrc/img/sprite/plantes/Pistopois.png")) {
		std::cout << "failed to load texture" << std::endl;
		exit(1);
	}
	m_sprite = new sf::Sprite();
	SetSize(m_texture->getSize().x, m_texture->getSize().y);
	m_sprite->setTexture(*m_texture);
	m_sprite->setOrigin(GetSize().x / 2, GetSize().y / 2);
}

void Pistopois::SetRate(float r) {
	m_rate = r;
}

void Pistopois::SetDamage(float d) {
	m_damage = d;
}

float Pistopois::GetRate() {
	return m_rate;
}

float Pistopois::GetDamage() {
	return m_damage;
}

