#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "FileManager.h"
#include "LevelManager.h"
#include "EventManager.h"

using namespace std;

typedef void(*func)();

class GameWindow;
class Hud;
class Zombie;
class Plante;
class Pistopois;
class SunFlower;
class Bullet;
class Sun;

typedef void(*func)();

class GameManager
{
private:

	// Main Attributes

	sf::Clock			clock;
	sf::Clock			pistoClock;
	sf::Clock			sunoClock;
	float				fpsLimit;

	EventManager		*eEventManager;
	
	bool				isPlaying;
	bool				isDone;
	bool				hasWon;
	bool				hasLost;

	float				sunRate;
	float				fsunFlowerDeltaTime;
	float				fsunDeltaTime;
	float				fpistoDeltaTime;
	float				fDeltaTime;

	// Window Attributes

	GameWindow			*window;
	Hud					*hud;
	sf::Shape			*CurrentPlant;
	sf::Sprite			*background;
	sf::Music			*music;

	

	// Objects Attributes

	int					money;
	int					typePlant;
	vector<Bullet*>		bullets;
	vector<Sun*>		suns;
	vector<Zombie*>		zombies;
	vector<Plante*>		plantes;
	vector<SunFlower*>	sunFlowers;
	vector<Pistopois*>	pistopois;
	map<string, float>	stats;


	vector<sf::String*>	wave;


public:

	GameManager();

	void				Start();

	~GameManager();
	static GameManager* pInstance;
	static void			Initialize()
	{
		GameManager::pInstance = new GameManager();
	}
	static GameManager* Get()
	{
		return pInstance;
	}

	// Plant Methods

	void				PlacePlante();

private:

	// Object Methods

	void				SpawnWave();
	void				GenerateWave();
	void				MoveZombies();
	void				SpawnZombie(float x, float y);
	void				GenerateSuns();
	void				SpawnSun(bool plant, int index);
	void				SetCurrentPlant(float x, float y);
	void				PistopoisShoot();
	void				DeleteBullet();
	void				DeleteSuns();

	// Window Methods

	void				RenderGame();
	void				LoseScreen();
	void				WinScreen();
	void				Credits();
	void				LimitFps();

	// Check Methods

	void				CheckColls();
	bool				IsOnSun(sf::Vector2i localposition);
	bool				IsOnPlay();
	bool				IsOnPisto(sf::Vector2i localposition);
	bool				IsOnPotatoe(sf::Vector2i localposition);
	bool				IsOnSunflower(sf::Vector2i localposition);
	void				CheckDefeat();
	void				CheckVictory();

	// Main Methods

	void				HandleEvents();
	
};

