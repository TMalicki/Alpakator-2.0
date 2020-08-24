#pragma once
#include "LoadSprite.h"

class SpriteAnimation
{
private:
	const LoadSprite& loadedSprite;
public:
	SpriteAnimation(const std::string& spriteLocalization) : loadedSprite{ spriteLocalization } {}
};