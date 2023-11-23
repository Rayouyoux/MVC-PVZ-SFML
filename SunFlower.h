#pragma once
#include "Plante.h"
#include <SFML/Graphics.hpp>

class SunFlower : public Plante
{
public:

	//Main Attributes

	sf::Clock	sunoClock;
	int			m_iRate;

	SunFlower(int m_id, float rate);
};

