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
void GameManager::SpawnZombie() {
	Zombie* oZombie = new Zombie();
	oZombie->SetPosition(1020, 800);
	zombies.push_back(oZombie);
}

void GameManager::PlacePlante() {
	Pistopois* oPistopois = new Pistopois(1);

	plantes.push_back(oPistopois);

	while (Mouse::isButtonPressed(Mouse::Button::Left) and window->w_window->hasFocus()) {
		oPistopois->SetPosition(window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).x, window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).y);
		RenderGame();
	}
	if (oPistopois->CanBePlaced(window) == false)
		plantes.pop_back();
	else
		money -= 100;
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
		
	}
}


void GameManager::LimitFps() {
	sf::Clock oClock;
	fDeltaTime = oClock.restart().asSeconds();
	//if (g_deltaTime < g_fpsLimit) {
	//	sleep(seconds(g_fpsLimit - g_deltaTime));
	//	g_deltaTime += g_fpsLimit - g_deltaTime;
	//}
}