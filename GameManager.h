#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class GameWindow;

class GameManager
{
private:
	
	// Main Attributes

	bool		isDone;
	bool		hasWon;
	bool		hasLost;

	// Window Attributes

	GameWindow*	window;
	sf::Sprite* background;
	//Vector2f	MousePos;

	// Objects Attributes

	//std::vector<Ball*>	balls;
	//std::vector<Zombie*>	zombies;
	//std::vector<Plante*>	plantes;
	



public:

	GameManager();

	void		Start();

	~GameManager();

private:

	// Main Methods

	void		HandleEvents();
};

