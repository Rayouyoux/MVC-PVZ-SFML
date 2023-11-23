#pragma once

#include "GameObject.h"

class GameWindow;

class Plante : public GameObject
{
private:

	// Main Attributes

	int		m_id;
	float	m_hp;
	int		m_hpMax;
	bool	m_powerAvailable;

public:

	Plante(int id);

	// Get methods

	int		GetHP();
	int		GetHPmax();
	bool	GetPowerUpStatus();
	int		GetId();

	// Set methods

	void	SetHp(float hp);

	// Main methods
	
	bool	CanBePlaced(GameWindow* window);
	void    DecreaseLife(float value);
};



