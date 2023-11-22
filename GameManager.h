#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameWindow;
class Zombie;
class Plante;
class Hud;

class GameManager
{
private:
	
	// Main Attributes

	bool		isDone;
	bool		hasWon;
	bool		hasLost;

	float		fDeltaTime;
	// Window Attributes

	GameWindow	*window;
	Hud			*hud;
	sf::Sprite	*background;
	sf::Music	*music;

	// Objects Attributes

	int						money;
	//std::vector<Ball*>	balls;
	std::vector<Zombie*>	zombies;
	std::vector<Plante*>	plantes;
	



public:

	GameManager();

	void		Start();

	~GameManager();

private:

	// Main Methods

	void		PlacePlante();
	void		SpawnZombie();

	void		HandleEvents();
	bool		IsOnPlay();

	void		RenderGame();

	void LimitFps();
};

