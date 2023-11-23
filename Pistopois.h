#pragma once
#include "Plante.h"
#include <vector>
#include "Bullet.h"
#include <SFML/Graphics.hpp>


class Pistopois : public Plante
{
private:
	
	float		m_damage;

public:

	// Main attributes

	float		m_rate;
	sf::Clock	pistopoisoClock;


	Pistopois(int id, float rate, float dmg);

	// Set methods

	void		SetRate(float r);
	void		SetDamage(float d);

	// Get methods

	float		GetRate();
	
	float		GetDamage();

	// Main methods

	void		Shoot(std::vector<Bullet*>* bullets);

};

