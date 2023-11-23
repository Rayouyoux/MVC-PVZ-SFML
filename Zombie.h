#pragma once
#include "GameObject.h"
#include <vector>

class Zombie : public GameObject
{
private:
	int					m_Speed;
	int					m_Hp;
	int					m_HpMax;
	float				m_Damage;
	std::vector<float>	m_vDirection;

public:

	Zombie(int m_id);

	float		GetHp();
	void	DecreaseLife(float value);
	void	setStats(float fSpeed, float fHp, float fMaxHp, float fDamage);
	bool	CheckCollision(GameObject* object);

	void	move(float fDeltaTime);
};

