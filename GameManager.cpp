#include "GameManager.h"

#include <iostream>
#include <SFML/System/Sleep.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "GameWindow.h"
#include "Menu.h"
#include "HUD.h"

#include "Pistopois.h"
#include "Zombie.h"

/*
---------------------------------------------------------------------------------
|						Here is the constructeur								|
---------------------------------------------------------------------------------
*/

GameManager::GameManager(){


	isDone = false;
	hasWon = false;
	hasLost = false;

	money = 1000;

	fDeltaTime = 0;



	window = new GameWindow();
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("rsrc/img/background.png")) {
		std::cout << "failed to load background" << std::endl;
		exit(1);
	}
	background = new sf::Sprite();
	background->setTexture(*texture);
	background->setOrigin(860, 540);
	background->setPosition(860, 540);
	background->setColor(sf::Color(255, 255, 255, 200));

	hud = new Hud(window);

	music = new Music();
	if (!music->openFromFile("rsrc/music/levels/level.ogg"))
	{
		std::cout << "Error loading level.ogg" << std::endl;
		exit(1);
	}
	music->setVolume(10.0f);
	music->setLoop(true);

}

/*
---------------------------------------------------------------------------------
|					Here are all the objects methods							|
---------------------------------------------------------------------------------
*/
void GameManager::SpawnZombie(float x, float y) {
	Zombie* oZombie = new Zombie();
	oZombie->SetPosition(x, y);
	zombies.push_back(oZombie);
	
}

void GameManager::MoveZombies() {
	if (!zombies.empty()) {
		for (int i = 0; i < zombies.size(); ++i) {
			zombies.at(i)->move(fDeltaTime);
		}
	}
}

void GameManager::PlacePlante() {
	Pistopois* oPistopois = new Pistopois(1);

	plantes.push_back(oPistopois);
	pistopois.push_back(oPistopois);

	while (Mouse::isButtonPressed(Mouse::Button::Left) and window->w_window->hasFocus()) {
		oPistopois->SetPosition(window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).x, window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).y);
		RenderGame();
	}
	if (oPistopois->CanBePlaced(window) == false)
		plantes.pop_back();
	else
		money -= 100;
}

void GameManager::PistopoisShoot() {
	if (!pistopois.empty()) {
		for (int i = 0; i < pistopois.size(); i++) {
			pistopois[i]->Shoot(&bullets);
		}
	}
}

void GameManager::DeleteBullet() {
	if (!bullets.empty()) {
		for (int i = 0; i < bullets.size(); i++) {
			if (bullets[i]->GetPosistion().x > 1920) {
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
				std::cout << "papagnan" << std::endl;
			}
		}
	}
}

/*
---------------------------------------------------------------------------------
|				Here are all Rendering related methods							|
---------------------------------------------------------------------------------
*/

void		GameManager::RenderGame() {
	window->Clear();
	window->w_window->draw(*background);
	if (!plantes.empty()) {
		for (int i = 0; i < plantes.size(); ++i)
			window->DrawObject(plantes.at(i));
	}
	// à bouger dans le moove zombie
	if (!bullets.empty()) {
		for (int i = 0; i < bullets.size(); i++) {
			bullets[i]->Move(fDeltaTime);
			window->DrawObject(bullets.at(i));
		}
	}
	if (!zombies.empty()) {
		for (int i = 0; i < zombies.size(); ++i) {
			window->DrawObject(zombies.at(i));
		}
	}
	hud->DrawHud(money, 50);
	window->Display();
}

/*
---------------------------------------------------------------------------------
|					Here are all the main methods								|
---------------------------------------------------------------------------------
*/

void		GameManager::Start() {
	Menu	menu(window, music);

	menu.Start();
	
	music->play();
	music->setVolume(menu.GetVolume());
	sf::sleep(sf::milliseconds(200));
	window->Clear();
	while (!isDone)
	{
		HandleEvents();
	}
}

GameManager::~GameManager() {
	plantes.clear();
	music->stop();
	delete music;
}



void GameManager::Defeat() {
	for (int i = 0; i < zombies.size(); ++i) {
		if (zombies[i]->GetPosistion().x < 0.2 * window->GetWidth()) {
			window->Close();
		}
	}
}
/*
---------------------------------------------------------------------------------
|								A bouger										|
---------------------------------------------------------------------------------
*/

bool GameManager::IsOnPlay() {
	if (window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).x > 0.876 * window->GetWidth() and \
		window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).x < 0.96 * window->GetWidth() and \
		window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).y > 0.455 * window->GetHeight() and \
		window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).y < 0.52 * window->GetHeight())
		return true;
	return false;
}

void GameManager::HandleEvents() {
	Event	event; 
	sf::Clock oClock;

	SpawnZombie(1980,800);
	while (true) {

		while (window->w_window->pollEvent(event))
		{
			SpawnZombie();
			LimitFps();
			/*move();*/
			sf::Vector2i localposition = sf::Mouse::getPosition(*window->w_window);
			if (event.type == Event::Closed)
				window->Close();
			if (Mouse::isButtonPressed(Mouse::Button::Left) and IsOnPlay())
				std::cout << "PLAY" << std::endl;
			else if (Mouse::isButtonPressed(Mouse::Button::Left) and window->w_window->hasFocus()) {
				
				if (money >= 100)
					PlacePlante();
			}
			RenderGame();
			
			
			
		}
		
		LimitFps();
		MoveZombies();
		Defeat();
		DeleteBullet();
		RenderGame();
		
	}
}


void	GameManager::GenerateWave() {
	float	x = 1920;
	float	y = 80;
	int		sizeX = wave.at(0)->getSize();
	int		sizeY = wave.size();

	for (int i = 0; i < sizeY; ++i) {
		for (int j = 0; j < sizeX; ++j) {
			if (wave.at(i)[j] != '-') {
				SpawnZombie(x, y);
			}
			x += (60);
		}
		x = 60;
		y += 60;
	}
	if (zombies.empty())
	{
		std::cout << "Error Generating Terrain. Terrain must not be empty" << std::endl;
		exit(1);
	}
void GameManager::LimitFps() {
	fDeltaTime = clock.restart().asSeconds();
	if (pistoClock.getElapsedTime().asSeconds() >= 2) {
		fpistoDeltaTime = pistoClock.restart().asSeconds();
		PistopoisShoot();
	}
	//if (g_deltaTime < g_fpsLimit) {
	//	sleep(seconds(g_fpsLimit - g_deltaTime));
	//	g_deltaTime += g_fpsLimit - g_deltaTime;
	//}
}