#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Timer
{
private:
	sf::Time time;
	sf::Clock clock;
public:
	Timer() : clock{}, time{} {}

	sf::Time getActualTime() { return clock.getElapsedTime(); }
	auto getActualTimeInMs() { return clock.getElapsedTime().asMilliseconds(); }
	float getElapsedTimeInMs() { return clock.getElapsedTime().asMicroseconds() / 1000.0f; }
	bool setDelay(float delayedTime) 
	{ 
		if (getElapsedTimeInMs() >= delayedTime)
		{
			clock.restart();
			return true;
		}
		else return false;
	}
};