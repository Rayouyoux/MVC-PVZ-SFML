#pragma once
#include "GameObject.h"
#include "SFML/Graphics.hpp"

class Sun : public GameObject
{
private:
	
	float		m_speed;
	sf::Vector2f m_direction;

public:
	Sun(float rate, float speed, float value);
	float		m_value;
	void		SetSpeed(float s);
	void		SetDirection(float x, float y);
	void		Move(float dt);
};

