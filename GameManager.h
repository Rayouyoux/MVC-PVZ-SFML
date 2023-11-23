#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "Pistopois.h"
#include "FileManager.h"
#include "EventManager.h"

class GameWindow;
class Zombie;
class Plante;
class SunFlower;
class Sun;
class Hud;
typedef void(*func)();
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

	GameWindow* window;
	Hud* hud;
	sf::Sprite* background;
	sf::Music*	music;

	// Objects Attributes
	EventManager* eEventManager;

	int						money;
	std::vector<Bullet*>	bullets;
	std::vector<Sun*>		suns;
	std::vector<Zombie*>	zombies;
	std::vector<Plante*>	plantes;
	std::vector<SunFlower*> sunFlowers;
	std::vector<Pistopois*> pistopois;
	std::map<std::string, float> stats;


	std::vector<sf::String*>	wave;


public:

	GameManager();

	void		Start();

	~GameManager();
	/*static GameManager* pInstance;
	static void Initialize()
	{
		GameManager::pInstance = new GameManager();
	}
	static GameManager* Get()
	{
		return pInstance;
	}*/
	void		PlacePlante(int a);

private:
	
	// Main Methods

	void		GenerateWave();
	
	void		SpawnSun(bool plant);
	void		SpawnZombie(float x, float y);
	void		CheckColls();

	void		HandleEvents();
	bool		IsOnSun(sf::Vector2i localposition);
	bool		IsOnPlay();

	void		RenderGame();
	void		CheckDefeat();
	void		CheckVictory();

	void		LoseScreen();
	void		WinScreen();
	void		Credits();

	void		MoveZombies();

	void        PistopoisShoot();
	void		DeleteBullet();

	void		LimitFps();
};

