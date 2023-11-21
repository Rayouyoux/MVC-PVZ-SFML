#include "Plante.h"

#include <iostream>


Plante::Plante (int id) : GameObject(){

	m_id = id;
	m_hp = 50;
	m_hpMax = 50;
	m_powerAvailable = false;
}

int		Plante::GetHP(){
	return m_hp;
}
int		Plante::GetHPmax(){
	return m_hpMax;
}
bool	Plante::GetPowerUpStatus(){
	return m_powerAvailable;
}