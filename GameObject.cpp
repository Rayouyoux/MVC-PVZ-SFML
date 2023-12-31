#include "GameObject.h"

/*
---------------------------------------------------------------------------------
|						Here is the constructeur								|
---------------------------------------------------------------------------------
*/

GameObject::GameObject() {

	m_position.x = NULL;
	m_position.y = NULL;
	m_size.x = NULL;
	m_size.y = NULL;
	m_sprite = nullptr;
}

/*
---------------------------------------------------------------------------------
|							Here is the set methods								|
---------------------------------------------------------------------------------
*/

void GameObject::SetPosition(float x, float y) {
	m_position.x = (x);
	m_position.y = (y);
	m_sprite->setPosition(x, y);
}

void GameObject::SetSize(float w, float h) {
	m_size.x = (w);
	m_size.y = (h);
}

/*
---------------------------------------------------------------------------------
|							Here is the get methods								|
---------------------------------------------------------------------------------
*/

sf::Vector2f GameObject::GetPosition() {
	sf::Vector2f pos(m_position.x, m_position.y);
	return pos;
}

sf::Vector2f GameObject::GetSize() {
	sf::Vector2f size(m_size.x, m_size.y);
	return size;
}
