#pragma once
#include "Plante.h"
#include <SFML/Graphics.hpp>

class SunFlower : public Plante
{
public:
	int m_iRate;
	SunFlower(int m_id, float rate);
	sf::Clock	sunoClock;

};

