#pragma once

#include "GameSettings.h"
#include "Draw.h"
#include "Event.h"

class Game
{
private:
	sf::RenderWindow window;

	Event event;
	Draw draw;
	GameSettings gameSettings;
public:
	Game(unsigned int width = 1000, unsigned int height = 600) : gameSettings(width, height), window{ sf::VideoMode(width, height), "ALPAKATOR 2.0", /*sf::Style::Fullscreen*/ }, draw{} {};
	
	//void initializeGame() { event.getWindow(window), draw.getWindow(window) }; // add it if necessary (for not sending window with every new method of those classes)
	void run();
};