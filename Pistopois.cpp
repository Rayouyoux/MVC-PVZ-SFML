#include "Pistopois.h"

#include <iostream>

/*
---------------------------------------------------------------------------------
|							Here is the constructor								|
---------------------------------------------------------------------------------
*/

Pistopois::Pistopois(int id, float rate, float dmg) : Plante(id) {
	m_rate = rate;
	m_damage = dmg;
	SetSize(100, 100);
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

/*
---------------------------------------------------------------------------------
|						Here are the set methods								|
---------------------------------------------------------------------------------
*/

void Pistopois::SetRate(float r) {
	m_rate = r;
}

void Pistopois::SetDamage(float d) {
	m_damage = d;
}

/*
---------------------------------------------------------------------------------
|						Here are the get methods								|
---------------------------------------------------------------------------------
*/

float Pistopois::GetRate() {
	return m_rate;
}

float Pistopois::GetDamage() {
	return m_damage;
}

/*
---------------------------------------------------------------------------------
|						Here are the main methods								|
---------------------------------------------------------------------------------
*/

void Pistopois::Shoot(std::vector<Bullet*>* bullets) {
	bullets->push_back(new Bullet(m_position.x + GetSize().x/2, m_position.y - 25));
}
