#include "Zombie.h"

#include <iostream>


/*
---------------------------------------------------------------------------------
|							Here is the constructor								|
---------------------------------------------------------------------------------
*/

Zombie::Zombie(int m_id) : GameObject() {
	m_Speed = 0;
	m_vDirection;
	m_vDirection.push_back(-1);
	m_Idle = false;

	sf::Texture* m_texture = new sf::Texture();
	if (m_id == 1) {
		if (!m_texture->loadFromFile("rsrc/img/sprite/zombies/Zombie.png")) {
			std::cout << "failed to load texture" << std::endl;
			exit(1);
		}
	}
	else if (m_id == 2) {
		if (!m_texture->loadFromFile("rsrc/img/sprite/zombies/Buckethead_Zombie.png")) {
			std::cout << "failed to load texture" << std::endl;
			exit(1);
		}
	}

	m_sprite = new sf::Sprite();
	SetSize(m_texture->getSize().x, m_texture->getSize().y);
	m_sprite->setTexture(*m_texture);
	m_sprite->setOrigin(GetSize().x / 2, GetSize().y / 2);
}

/*
---------------------------------------------------------------------------------
|							Here are the get methods							|
---------------------------------------------------------------------------------
*/

float		Zombie::GetHp() {
	return m_Hp;
}

float		Zombie::GetSpeed() {
	return m_Speed;
}

float		Zombie::GetDmg() {
	return m_Damage;
}

/*
---------------------------------------------------------------------------------
|							Here are the set methods							|
---------------------------------------------------------------------------------
*/

void Zombie::setStats(float fSpeed, float fHp, float fMaxHp, float fDamage) {
	m_Speed = fSpeed;
	m_CurrentSpeed = fSpeed;
	m_Hp = fHp;
	m_HpMax = fMaxHp;
	m_Damage = fDamage;
}

void    Zombie::SetSpeed(int value) {
	m_CurrentSpeed = value;
}

/*
---------------------------------------------------------------------------------
|							Here are the main methods							|
---------------------------------------------------------------------------------
*/

void Zombie::DecreaseLife(float value) {
	m_Hp -= value;
}

bool Zombie::CheckCollision(GameObject* object) {
	if (GetPosition().x - GetSize().x / 2 <= object->GetPosition().x + object->GetSize().x / 2 and \
		object->GetPosition().y >= GetPosition().y - GetSize().y / 2 and \
		object->GetPosition().y <= GetPosition().y + GetSize().y / 2) {
		return true;
	}
	return false;
}

void Zombie::move(float fDeltaTime) {
	if(m_Idle == false){
		m_position.x -= 10 * fDeltaTime * m_CurrentSpeed;
		SetPosition(m_position.x, m_position.y);
	}

}


