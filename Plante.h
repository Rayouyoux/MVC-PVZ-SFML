#pragma once
#include "GameObject.h"

class GameWindow;

class Plante : public GameObject
{
private:

	// Main Attributes

	int		m_id;
	float		m_hp;
	int		m_hpMax;
	bool	m_powerAvailable;

public:

	Plante(int id);

	// Main Methods
	
	bool	CanBePlaced(GameWindow* window);
	int		GetHP();
	int		GetHPmax();
	bool	GetPowerUpStatus();
	int		GetId();
	void	SetHp(float hp);
	void    DecreaseLife(float value);
};



