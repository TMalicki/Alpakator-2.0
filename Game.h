#pragma once

#include "SettingClasses/GameSettings.h"
#include "MapClasses/LoadWorld.h"
#include "CreaturesClasses/CreaturesInterface.h"
#include "Hero.h"
#include "Gorgon.h"
#include "Draw.h"
#include "Event.h"

class Game
{
private:
	sf::RenderWindow window;

	Event event;
	Draw draw;
	GameSettings gameSettings;
	LoadWorld loadWorld;
	std::unique_ptr<CreaturesInterface> hero;
	std::unique_ptr<CreaturesInterface> gorgon;
public:
	Game(unsigned int tileWidth = 40, unsigned int tileHeight = 40, unsigned int tileAmountHorizon = 30, unsigned int tileAmountVertical = 24)
		: gameSettings(tileWidth, tileHeight, tileAmountHorizon, tileAmountVertical)
		, loadWorld(gameSettings.getSettings())
		, hero{ std::make_unique<Hero>(100.0f, 5.0f, 3.0f, 2.0f, sf::Vector2f{ 0.0f, 0.0f }) }
		, gorgon{ std::make_unique<Gorgon>(100.0f, 5.0f, 3.0f, 2.0f, sf::Vector2f{ 150.0f, 150.0f })}
		, window{ sf::VideoMode(tileWidth * tileAmountHorizon, tileHeight * tileAmountVertical), "ALPAKATOR 2.0" }, draw{} 
	{
		gorgon->creaturesSpawn(sf::Vector2f{ 50.0f, 50.0f });
		hero->creaturesSpawn(sf::Vector2f{ 0.0f, 0.0f });
	};
	
	//void initializeGame() { event.getWindow(window), draw.getWindow(window) }; // add it if necessary (for not sending window with every new method of those classes)
	void run();
	void load();
};