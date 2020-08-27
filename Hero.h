#pragma once
#include "CreaturesClasses/CreaturesInterface.h"

class Hero : public CreaturesInterface
{
private:

public:
	Hero(float hp, float atk, float def, float agil, sf::Vector2f pos) : CreaturesInterface(hp, atk, def, agil, pos) { creatureLoad(); }
	virtual void creatureLoad() { sCreatures = std::make_unique<SpriteAnimation>("characterSprites/alpacaMove.png"); }
};