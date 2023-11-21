#pragma once
#include "Plante.h"

class Pistopois : public Plante
{
private:
	float m_rate;
	float m_damage;
public:
	
	Pistopois(int id);

	void SetRate(float r);

	void SetDamage(float d);

	float GetRate();
	
	float GetDamage();

};

