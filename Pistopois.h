#pragma once
#include "Plante.h"
#include <vector>
#include "Bullet.h"
#include <SFML/Graphics.hpp>


class Pistopois : public Plante
{
private:
	
	float m_damage;
public:
	float		m_rate;
	sf::Clock	pistopoisoClock;
	Pistopois(int id, float rate, float dmg);

	void		SetRate(float r);

	void		SetDamage(float d);

	float		GetRate();
	
	float		GetDamage();

	void		Shoot(std::vector<Bullet*>* bullets);

};

