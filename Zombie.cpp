#include "Zombie.h"

#include <iostream>

Zombie::Zombie() : GameObject() {
	m_Speed = 3;
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

float		Zombie::GetHp() {
	return m_Hp;
}

void Zombie::DecreaseLife(float value) {
	m_Hp -= value;
}

bool Zombie::CheckCollision(GameObject* object) {
	if (GetPosition().x - GetSize().x / 2 <= object->GetPosition().x + object->GetSize().x / 2 and \
		object->GetPosition().y >= GetPosition().y - GetSize().y / 2 and \
		object->GetPosition().y <= GetPosition().y + GetSize().y / 2) {
		DecreaseLife(10);
		return true;
	}
	return false;
}

void Zombie::move(float fDeltaTime) {
	m_position.x -= 10 * fDeltaTime * m_Speed;
	SetPosition(m_position.x, m_position.y);
}

void Zombie::setStats(float fSpeed, float fHp, float fMaxHp, float fDamage) {
	m_Speed = fSpeed;
	m_Hp = fHp;
	m_HpMax = fMaxHp;
	m_Damage = fDamage;
}
