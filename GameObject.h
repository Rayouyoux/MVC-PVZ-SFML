#pragma once
#include "SFML/Graphics.hpp"
namespace sf{
	class Sprite;
}
class GameObject
{
private:

	
	sf::Vector2f m_size;

public:
	sf::Vector2f m_position;
	sf::Sprite* m_sprite;

	GameObject();

	void SetPosition(float x, float y);

	void SetSize(float w, float h);

	sf::Vector2f GetPosistion();

	sf::Vector2f GetSize();
};

