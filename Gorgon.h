#pragma once
#include "CreaturesClasses/CreaturesInterface.h"

class Gorgon : public CreaturesInterface
{
private:

public:
	Gorgon(float hp, float atk, float def, float agil, sf::Vector2f pos) : CreaturesInterface(hp, atk, def, agil, pos) { creatureLoad(); }
	virtual void creatureLoad() { sCreatures = std::make_unique<SpriteAnimation>("characterSprites/gorgon.png", 55, 64); }
	virtual void notify() { std::for_each(listObserver.begin(), listObserver.end(), [&](ObserverInterface* observer) { observer->updateMonster(sCreatures->getSprite()); }); }
};