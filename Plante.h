#pragma once
#include "GameObject.h"

class GameWindow;

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
	
	bool	CanBePlaced(GameWindow* window);
	void		SetHP(int hp);
	int		GetHP();
	int		GetHPmax();
	bool	GetPowerUpStatus();
	int    GetId();
};



