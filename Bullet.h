#pragma once
#include "GameObject.h"
#include "SFML/Graphics.hpp"
class Bullet : public GameObject
{
private:
	float m_speed;
	sf::Vector2f m_direction;
public:

	Bullet(float posx,float posy);

	void SetSpeed(float s);

	void SetDirection(float x, float y);

	void Move(float dt);
};

