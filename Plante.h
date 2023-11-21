#pragma once
#include "GameObject.h"

class Plante : public GameObject
{
private:

	// Main Attributes

	int		m_id;
	int		m_hp;
	int		m_hpMax;
	bool	m_powerAvailable;

public:

	Plante(int id);

	// Main Methods
	
	int		GetHP();
	int		GetHPmax();
	bool	GetPowerUpStatus();
};



