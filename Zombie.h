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
	Zombie();
	void	move(float fDeltaTime);
};

