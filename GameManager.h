#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "Pistopois.h"

class GameWindow;
class Zombie;
class Plante;
class Hud;

class GameManager
{
private:
	
	// Main Attributes

	sf::Clock	clock;
	sf::Clock	pistoClock;

	bool		isDone;
	bool		hasWon;
	bool		hasLost;


	float		fpistoDeltaTime;
	float		fDeltaTime;
	// Window Attributes

	GameWindow	*window;
	Hud			*hud;
	sf::Sprite	*background;
	sf::Music	*music;

	// Objects Attributes

	int						money;
	std::vector<Bullet*>	bullets;
	std::vector<Zombie*>	zombies;
	std::vector<Plante*>	plantes;
	std::vector<Pistopois*> pistopois;
	



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

	void        PistopoisShoot();
	void		DeleteBullet();

	void		LimitFps();
};

