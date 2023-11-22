#include "Plante.h"

#include <iostream>

#include "GameWindow.h"


Plante::Plante (int id) : GameObject(){

	m_id = id;
	m_hp = 50;
	m_hpMax = 50;
	m_powerAvailable = false;
}

bool	Plante::CanBePlaced(GameWindow *window) {
	if (GetPosistion().x < 0.2 * window->GetWidth() or \
		GetPosistion().x > 0.8 * window->GetWidth() or \
		GetPosistion().y < 0.1 * window->GetHeight() or \
		GetPosistion().y > 0.9 * window->GetHeight())
		return false;
	return true;
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
int Plante::GetId() {
	return m_id;
}