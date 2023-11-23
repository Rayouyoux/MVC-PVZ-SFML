#pragma once
#include "GameObject.h"
#include "SFML/Graphics.hpp"

class Sun : public GameObject
{
private:
	
	float			m_speed;
	sf::Vector2f	m_direction;

public:

	// Main Attributes

	float		m_rate;
	float		m_value;

	Sun(float rate, float speed, float value);

	// Set methods

	void		SetSpeed(float s);
	void		SetDirection(float x, float y);

	// Main methods

	void		Move(float dt);

};

