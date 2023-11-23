#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "Pistopois.h"
#include "FileManager.h"
#include "LevelManager.h"
#include "EventManager.h"
typedef void(*func)();
using namespace std;
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
	sf::Clock	sunoClock;
	
	bool		isPlaying;
	bool		isDone;
	bool		hasWon;
	bool		hasLost;

	float		sunRate;
	float		fsunFlowerDeltaTime;
	float		fsunDeltaTime;
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
	vector<Bullet*>	bullets;
	vector<Sun*>		suns;
	vector<Zombie*>	zombies;
	vector<Plante*>	plantes;
	vector<SunFlower*> sunFlowers;
	vector<Pistopois*> pistopois;
	map<string, float> stats;


	vector<sf::String*>	wave;


public:

	GameManager();

	void		Start();

	~GameManager();
	static GameManager* pInstance;
	static void Initialize()
	{
		GameManager::pInstance = new GameManager();
	}
	static GameManager* Get()
	{
		return pInstance;
	}
	int         typePlant = 0;
	void		PlacePlante();

private:
	
	// Main Methods

	void		GenerateWave();
	
	void		SpawnSun(bool plant, int index);

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
	void        DeleteSuns();

	void		LimitFps();
};

