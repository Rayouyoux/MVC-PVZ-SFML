#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include "GameObject.h"


typedef void(*func)();
using namespace std;

class EventManager
{
private:
	static EventManager* eInstance;

public:
	static void Initialize()
	{
		EventManager::eInstance = new EventManager();
	}

	static EventManager* Get()
	{
		return eInstance;
	}

public:
	map<sf::Event::EventType, map<sf::Mouse::Button, func>> m_cMouseMap;
	map<sf::Event::EventType, map<sf::Keyboard::Key, func>> m_cKeyboardMap;

	void AddComponent(sf::Event::EventType eventType, sf::Mouse::Button mouseEvent, func event);

	void AddComponent(sf::Event::EventType eventType, sf::Keyboard::Key keyEvent, func event);

	EventManager();

	EventManager(func* event);

	void Update(sf::RenderWindow* oWindow, int typePlant, int money);

	void ManageEvent(sf::Event::EventType eType, sf::Mouse::Button mousePressed);

	void ManageEvent(sf::Event::EventType eType, sf::Keyboard::Key keyPressed);
};
