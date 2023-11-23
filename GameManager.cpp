#include "GameManager.h"

#include <iostream>
#include "time.h"
#include <SFML/System/Sleep.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "GameWindow.h"
#include "Menu.h"
#include "HUD.h"

#include "Pistopois.h"
#include "Patate.h"
#include "SunFlower.h"
#include "Zombie.h"
#include "Sun.h"
sf::Event pressed;

GameManager* GameManager::pInstance = nullptr;
/*
---------------------------------------------------------------------------------
|						Here is the constructeur								|
---------------------------------------------------------------------------------
*/

GameManager::GameManager() {


	isDone = false;
	hasWon = false;
	hasLost = false;

	money = 1000;

	fDeltaTime = 0;
	fpistoDeltaTime = 0; 
	fsunFlowerDeltaTime = 0;
	fsunDeltaTime = 0;

	sunRate = 10;

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

	FileManager statsFileManager("stats/stats.txt");
	std::vector<std::string> vsFileLines = statsFileManager.readFileLines();
	stats = statsFileManager.getStatsMap(vsFileLines);
}

/*
---------------------------------------------------------------------------------
|					Here are all the objects methods							|
---------------------------------------------------------------------------------
*/
void GameManager::SpawnSun(bool plant, int index) {


	int xPos = 0;
	int y = 0;
	Sun* oSun = new Sun(stats["sun_rate"], stats["sun_speed"], stats["sun_value"]);
	sunRate = oSun->m_rate;
	if (plant == false) {
		int xPos = (int)oSun->GetSize().x + (rand() % (int(window->GetWidth() - oSun->GetSize().x)));
		int y = -10;
		suns.push_back(oSun);
		oSun->SetPosition(xPos, y);
		
	}
	else {
		//for (int i = 0; i < sunFlowers.size(); i++) {
			int xPos = sunFlowers[index]->GetPosition().x;
			int y = sunFlowers[index]->GetPosition().y;
			oSun->SetSpeed(0);
			suns.push_back(oSun);
			oSun->SetPosition(xPos, y);
		//}
		
	}
}

void GameManager::DeleteSuns() {
	if (!suns.empty()) {
		for (int i = 0; i < suns.size(); i++) {
			if (suns[i]->GetPosition().y > window->GetHeight()) {
				delete suns[i];
				suns.erase(suns.begin() + i);
			}
		}
	}
}
void GameManager::SpawnZombie(float x, float y) {
	Zombie* oZombie = new Zombie(2);
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
	if (typePlant == 1) {
		Pistopois* oPlante = new Pistopois(1, stats["pistopois_rate"], stats["pistopois_dmg"]);
		plantes.push_back(oPlante);
		while (Mouse::isButtonPressed(Mouse::Button::Left) and window->w_window->hasFocus()) {
			oPlante->SetPosition(window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).x, window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).y);
			RenderGame();

		}
		if (oPlante->CanBePlaced(window) == false) {
			plantes.pop_back();
			pistopois.pop_back();
		}
		else
		{
			pistopois.push_back(oPlante);
			money -= stats["pistopois_cost"];
		}
	}
	else if (typePlant == 2) {
		Patate* oPlante = new Patate(2, stats["patate_hp"]);
		plantes.push_back(oPlante);
		while (Mouse::isButtonPressed(Mouse::Button::Left) and window->w_window->hasFocus()) {
			oPlante->SetPosition(window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).x, window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).y);
			RenderGame();
		}
		if (oPlante->CanBePlaced(window) == false) {
			plantes.pop_back();
		}
		else
		{
			money -= stats["patate_cost"];
		}
	}
	else if (typePlant == 3) {
		SunFlower* oPlante = new SunFlower(3, stats["sunflower_rate"]);
		
		plantes.push_back(oPlante);
		while (Mouse::isButtonPressed(Mouse::Button::Left) and window->w_window->hasFocus()) {
			oPlante->SetPosition(window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).x, window->w_window->mapPixelToCoords(Mouse::getPosition(*window->w_window)).y);
			RenderGame();
		}
		if (oPlante->CanBePlaced(window) == false) {
			plantes.pop_back();
		}
		else {
			sunFlowers.push_back(oPlante);
			money -= stats["sunflower_cost"];
		}
		

		

	}

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
			if (bullets[i]->GetPosition().x > window->GetWidth()) {
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
			}
		}
	}
}
void EventPlacePlants()
{
	GameManager::Get()->PlacePlante();
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
	// � bouger dans le moove zombie
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
	if (!suns.empty()) {
		for (int i = 0; i < suns.size(); i++) {
			
			suns[i]->Move(fDeltaTime);
			window->DrawObject(suns.at(i));
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



void GameManager::CheckDefeat() {
	for (int i = 0; i < zombies.size(); ++i) {
		if (zombies[i]->GetPosition().x < 0.2 * window->GetWidth()) {
			hasLost = true;
			isDone = true;
		}
	}
}

void GameManager::CheckVictory() {
	
	if (zombies.empty()) {
		hasWon = true;
		isDone = true;
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

bool GameManager::IsOnSun(sf::Vector2i localposition) {
	bool gotSun;

	gotSun = false;
	for (int i = 0; i < suns.size(); i++) {
		if (((suns[i]->GetPosition().x - suns[i]->GetSize().x / 2) < localposition.x && (suns[i]->GetPosition().x + suns[i]->GetSize().x / 2) > localposition.x)
			&& ((suns[i]->GetPosition().y - suns[i]->GetSize().y / 2) < localposition.y && (suns[i]->GetPosition().y + suns[i]->GetSize().y / 2) > localposition.y)) {
			money += suns[i]->m_value;
			suns.erase(suns.begin() + i);
			gotSun = true;
		}
	}
	return gotSun;
}

void GameManager::LoseScreen() {
	sf::Texture loseTexture;
	sf::Sprite	lose;
	Event		event;
	bool		loop = true;

	fDeltaTime = clock.restart().asSeconds();

	if (!loseTexture.loadFromFile("rsrc/img/losescreen/background.png")) {
		std::cout << "Error loading lose background" << std::endl;
		exit(1);
	}
	lose.setTexture(loseTexture);
	window->w_window->draw(lose);
	window->Display();

	if (!music->openFromFile("rsrc/music/lose/lose.ogg"))
	{
		std::cout << "Error loading lose.ogg" << std::endl;
		exit(1);
	}
	music->play();

	while (loop and clock.getElapsedTime().asSeconds() <= 10)
	{
		while (window->w_window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
				if (event.key.scancode == sf::Keyboard::Scan::Escape)
					loop = false;
			if (event.type == Event::Closed)
				exit(1);
		}
	}
	window->Clear();
	music->stop();
}

void GameManager::WinScreen() {
	sf::Texture winTexture;
	sf::Sprite	win;
	Event		event;
	bool		loop = true;

	fDeltaTime = clock.restart().asSeconds();

	if (!winTexture.loadFromFile("rsrc/img/winscreen/background.png")) {
		std::cout << "Error loading win background" << std::endl;
		exit(1);
	}
	win.setTexture(winTexture);
	window->w_window->draw(win);
	window->Display();

	if (!music->openFromFile("rsrc/music/win/win.ogg"))
	{
		std::cout << "Error loading win.ogg" << std::endl;
		exit(1);
	}
	music->play();

	while (loop and clock.getElapsedTime().asSeconds() <= 10)
	{
		while (window->w_window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
				if (event.key.scancode == sf::Keyboard::Scan::Escape)
					loop = false;
			if (event.type == Event::Closed)
				exit(1);
		}
	}
	window->Clear();
	music->stop();
}

void GameManager::Credits() {
	sf::Texture creditsTexture;
	sf::Sprite	credits;
	Event		event;
	bool		loop = true;
	//eEventManager->Get()->AddComponent(sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Escape, loop = false);

	fDeltaTime = clock.restart().asSeconds();

	if (!creditsTexture.loadFromFile("rsrc/img/credits/background.png")) {
		std::cout << "Error loading credits background" << std::endl;
		exit(1);
	}
	credits.setTexture(creditsTexture);
	credits.setPosition(0, 0);
	window->w_window->draw(credits);
	window->Display();

	if (!music->openFromFile("rsrc/music/credits/credits.ogg"))
	{
		std::cout << "Error loading win.ogg" << std::endl;
		exit(1);
	}
	music->play();

	while (loop)
	{
		fDeltaTime = clock.restart().asSeconds();
		window->Clear();
		while (window->w_window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
				if (event.key.scancode == sf::Keyboard::Scan::Escape)
					loop = false;
			if (event.type == Event::Closed)
				exit(1);
		}
		credits.setPosition(0, credits.getPosition().y - 50 * fDeltaTime);
		window->w_window->draw(credits);
		window->Display();
	}
	window->Clear();
	music->stop();
}

void GameManager::HandleEvents() {
	Event		event;
	EventManager::Initialize();
	eEventManager->Get()->AddComponent(sf::Event::EventType::MouseButtonPressed, sf::Mouse::Left, &EventPlacePlants);
	sf::Clock	oClock;
	bool keypressed = false;

	srand(time(NULL)); 
	SpawnZombie(1970, 800);
	SpawnZombie(1980, 600);
	SpawnZombie(1990, 400);
	while (!isDone) {
		//EventManager::Get()->Update(window->w_window, typePlant, money);

		while (window->w_window->pollEvent(event))
		{
			/*move();*/
			sf::Vector2i localposition = sf::Mouse::getPosition(*window->w_window);
			if (event.type == Event::Closed)
				window->Close();
			if (Keyboard::isKeyPressed(Keyboard::Num1)) {
				if (typePlant == 1 && keypressed == false) {
					typePlant = 0;
					keypressed = true;
				}
				else if(typePlant != 1 && keypressed == false) {
					typePlant = 1;
					keypressed = true;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Num2)) {
				if (typePlant == 2 && keypressed == false) {
					typePlant = 0;
					keypressed = true;
				}
				else if (typePlant != 2 && keypressed == false) {
					typePlant = 2;
					keypressed = true;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Num3)) {
				if (typePlant == 3 && keypressed == false) {
					typePlant = 0;
					keypressed = true;
				}
				else if (typePlant != 3 && keypressed == false) {
					typePlant = 3;
					keypressed = true;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Num1) == false && Keyboard::isKeyPressed(Keyboard::Num2) == false && Keyboard::isKeyPressed(Keyboard::Num3) == false) {
				keypressed = false;
			}
			if (Mouse::isButtonPressed(Mouse::Button::Left) and IsOnPlay())
				std::cout << "PLAY" << std::endl;
			else if (Mouse::isButtonPressed(Mouse::Button::Left) and window->w_window->hasFocus() and IsOnSun(localposition));
			else if (Mouse::isButtonPressed(Mouse::Button::Left) and window->w_window->hasFocus()) {
				if (money >= 100 and typePlant == 1)
					PlacePlante();
				if (money >= 150 and typePlant == 2)
					PlacePlante();
				if (money >= 50 and typePlant == 3)
					PlacePlante();
			}
		}
		LimitFps();
		CheckColls();
		MoveZombies();
		CheckDefeat();
		CheckVictory();
		DeleteBullet();
		DeleteSuns();
		RenderGame();
	}
	window->Clear();
	music->stop();
	if (hasLost)
		LoseScreen();
	else if (hasWon)
		WinScreen();
	Credits();

}

void    GameManager::CheckColls() {
	bool ZombieExist = true;

	for (int i = 0; i < zombies.size(); ++i) {
		for (int j = 0; j < bullets.size(); ++j)
		{
			if (ZombieExist)
			{
				if (zombies.at(i)->CheckCollision(bullets.at(j))) {
					delete bullets[j];
					bullets.erase(bullets.begin() + j);
					zombies.at(i)->DecreaseLife(10);
					if (zombies.at(i)->GetHp() <= 0) {
						delete zombies[i];
						zombies.erase(zombies.begin() + i);
						ZombieExist = false;
					}
				}
			}
		}
		ZombieExist = true;
	}

	for (int i = 0; i < zombies.size(); ++i) {
		for (int j = 0; j < plantes.size(); ++j)
		{
			if (zombies.at(i)->CheckCollision(plantes.at(j))) {
				zombies.at(i)->SetSpeed(0);
				plantes.at(j)->DecreaseLife(zombies.at(i)->GetDmg() * fDeltaTime);
				std::cout << plantes.at(j)->GetHP() << std::endl;
				if (plantes.at(j)->GetHP() <= 0)
				{
					delete plantes[j];
					plantes.erase(plantes.begin() + j);
					zombies.at(i)->SetSpeed(3);
				}
			}
		}
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
}

void GameManager::LimitFps() {
	fDeltaTime = clock.restart().asSeconds();
	if (pistoClock.getElapsedTime().asSeconds() >= 2) {
		fpistoDeltaTime = pistoClock.restart().asSeconds();
		PistopoisShoot();
	}
	else if (sunoClock.getElapsedTime().asSeconds() >= sunRate) {
		fsunDeltaTime = sunoClock.restart().asSeconds();
		SpawnSun(false, 0);
	}
	else if (!sunFlowers.empty()) {
		for (int i = 0; i < sunFlowers.size(); i++) {
			if (sunFlowers[i]->sunoClock.getElapsedTime().asSeconds() >= sunFlowers[i]->m_iRate) {
				fsunFlowerDeltaTime = sunFlowers[i]->sunoClock.restart().asSeconds();
				SpawnSun(true,i);
			}
		}
		
	}
	//if (g_deltaTime < g_fpsLimit) {
	//	sleep(seconds(g_fpsLimit - g_deltaTime));
	//	g_deltaTime += g_fpsLimit - g_deltaTime;
	//}

}


