#pragma once
#include "LoadSprite.h"

class SpriteInRect
{
private:
	//std::unique_ptr<LoadSprite> loadedSprite;
	LoadSprite loadedSprite;

	int width;
	int height;
public:
	SpriteInRect(const std::string& spriteLocalization, const int width, const int height) : loadedSprite{ spriteLocalization }, width{width}, height{height} 
	{
		loadedSprite.setTextureRect(0, 0, width, height);
	}

	void move(int verticalIndex, int horizontalIndex)
	{
		loadedSprite.setTextureRect(verticalIndex, horizontalIndex, width, height);
	}

	void setSpritePosition(sf::Vector2f position)
	{
		loadedSprite.setSpritePosition(position);
	}

	const sf::Sprite& getSprite() { return loadedSprite.getSprite(); }
};