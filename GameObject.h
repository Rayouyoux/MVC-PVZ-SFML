#pragma once

#include "SFML/Graphics.hpp"

class GameObject
{
private:

	sf::Vector2f	m_size;

public:

	// Main attributes

	sf::Vector2f	m_position;
	sf::Sprite*		m_sprite;

	GameObject();

	// Set Methods

	void			SetPosition(float x, float y);
	void			SetSize(float w, float h);

	// Get Methods

	sf::Vector2f	GetPosition();
	sf::Vector2f	GetSize();
};

