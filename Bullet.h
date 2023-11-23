#pragma once

#include "GameObject.h"
#include "SFML/Graphics.hpp"

class Bullet : public GameObject
{
private:

	sf::Vector2f	m_direction;
	float			m_speed;
	
public:

	// Constructor

	Bullet(float posx,float posy);

	// Set Methods

	void			SetSpeed(float s);
	void			SetDirection(float x, float y);

	// Main methods

	void			Move(float dt);
};

