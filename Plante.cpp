#include "Plante.h"

#include <iostream>

#include "GameWindow.h"


Plante::Plante(int id) : GameObject() {

	m_id = id;
	m_hp = 50;
	m_hpMax = 50;
	m_powerAvailable = false;
}

bool	Plante::CanBePlaced(GameWindow* window) {
	if (GetPosition().x < 0.2 * window->GetWidth() or \
		GetPosition().x > 0.8 * window->GetWidth() or \
		GetPosition().y < 0.1 * window->GetHeight() or \
		GetPosition().y > 0.9 * window->GetHeight())
		return false;
	return true;
}
void		Plante::SetHP(int hp) {
	m_hp = hp;
}

int		Plante::GetHP() {
	return m_hp;
}
int		Plante::GetHPmax() {
	return m_hpMax;
}
bool	Plante::GetPowerUpStatus() {
	return m_powerAvailable;
}
int Plante::GetId() {
	return m_id;
}

void Plante::SetHp(float hp) {
	m_hp = hp;
}

void Plante::DecreaseLife(float value) {
	m_hp -= value;
}