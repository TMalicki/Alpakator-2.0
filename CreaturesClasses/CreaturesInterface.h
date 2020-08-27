#pragma once

#include "SpriteAnimation.h"
#include "../ToolClasses/ObserverInterface.h"
#include "../ToolClasses/SubjectInterface.h"

class CreaturesInterface : public SubjectInterface
{
private:
	float hp;
	float attack;
	float defence;
	float agility;
	sf::Vector2f position;
	std::vector<ObserverInterface*> listObserver;

protected:
	std::unique_ptr<SpriteAnimation> sCreatures;

public:
	CreaturesInterface(float hp, float atk, float def, float agil, sf::Vector2f pos) : hp{}, attack{}, defence{}, agility{}, position{}, sCreatures{} {}; 
	virtual void creatureLoad() = 0;

	void creaturesSpawn(sf::Vector2f position) { sCreatures->setSpritePosition(position); };
	void creaturesMove() { sCreatures->moveRight();  notify(); }
	void update() { creaturesMove(); notify(); }

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
	virtual void notify() { std::for_each(listObserver.begin(), listObserver.end(), [&](ObserverInterface* observer) { observer->updateCreatures(sCreatures->getSprite()); }); }
};