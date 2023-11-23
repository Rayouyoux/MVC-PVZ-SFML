#pragma once
#include "Plante.h"
#include <vector>
#include "Bullet.h"

class Pistopois : public Plante
{
private:
	float m_rate;
	float m_damage;
public:
	
	Pistopois(int id, float rate, float dmg);

	void SetRate(float r);

	void SetDamage(float d);

	float GetRate();
	
	float GetDamage();

	void Shoot(std::vector<Bullet*>* bullets);

};

