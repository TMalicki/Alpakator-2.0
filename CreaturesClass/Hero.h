#pragma once
#include "SpriteAnimation.h"
#include "../ToolClasses/ObserverInterface.h"
#include "../ToolClasses/SubjectInterface.h"

class Hero : public SubjectInterface
{
private:
	float hp;
	float attack;
	float defence;
	float agility;
	sf::Vector2f position;
	SpriteAnimation sHero;

	std::vector<ObserverInterface*> listObserver;
public:
	Hero() : hp{}, attack{}, defence{}, agility{}, position{}, sHero{ "characterSprites/alpacaMove.png" } { heroSpawn(sf::Vector2f{ 0.0f, 0.0f }); };

	void heroSpawn(sf::Vector2f position) { sHero.setSpritePosition(position); };
	void heroMove() { sHero.moveRight();  notify(); }


	// observer design pattern methods
	virtual void attach(ObserverInterface* observer) { listObserver.push_back(observer); };
	virtual void detach(ObserverInterface* observer)
	{
		auto iterator = std::find(listObserver.begin(), listObserver.end(), observer);
		if (iterator != listObserver.end())
		{
			listObserver.erase(iterator); // memory leak
		}
	}
	virtual void notify() { std::for_each(listObserver.begin(), listObserver.end(), [&](ObserverInterface* observer) { observer->updateHero(sHero.getSprite()); }); }
};
