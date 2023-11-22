#pragma once
#include "GameObject.h"
#include <vector>

class Zombie : public GameObject
{
private:
	float					m_Speed;
	float					m_Hp;
	float					m_HpMax;
	float				m_Damage;
	std::vector<float>	m_vDirection;

public:

	Zombie();

	float		GetHp();
	void	DecreaseLife(float value);
	void	setStats(float fSpeed, float fHp, float fMaxHp, float fDamage);
	bool	CheckCollision(GameObject* object);

	void	move(float fDeltaTime);
};

