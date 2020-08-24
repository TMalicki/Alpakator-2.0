#pragma once
#include "SpriteInRect.h"

class SpriteAnimation
{
private:
	SpriteInRect spriteInRect;
	int index{ 0 };
	//limitPixelsWindow
public:
	SpriteAnimation(const std::string& spriteLocalization, const int width = 95, const int height = 141) : spriteInRect{ spriteLocalization, width, height } {}

	void moveRight()
	{
		if (index == 8) index = 0;
		spriteInRect.move(index, 0);
		index++;
	}

	void setSpritePosition(sf::Vector2f position)
	{
		spriteInRect.setSpritePosition(position);
	}

	const sf::Sprite& getSprite() { return spriteInRect.getSprite(); }
};