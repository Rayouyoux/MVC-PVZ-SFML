#pragma once
#include "Plante.h"
#include <SFML/Graphics.hpp>

class SunFlower : public Plante
{
public:
	float m_rate;
	sf::Clock	sunoClock;

	SunFlower(int m_id);
};

