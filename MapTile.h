#pragma once

#include "TilesTypesContainer.h"

class MapTile
{
private:
	TilesTypesContainer tilesTypeContainer;
	sf::Sprite tileSprite;
	sf::Texture tileTexture;
	sf::Vector2f position;
	sf::Vector2u tileSize;
public:
	MapTile(sf::Vector2u tileSize) : position{}, tilesTypeContainer{}, tileSize{ tileSize } { }
	
	void setSpriteScale() 
	{
		sf::Vector2f textureSize = sf::Vector2f{ tileSprite.getLocalBounds().width, tileSprite.getLocalBounds().height };
		sf::Vector2f spriteScale = sf::Vector2f{ static_cast<float>(tileSize.x) / static_cast<float>(textureSize.x), static_cast<float>(tileSize.y) / static_cast<float>(textureSize.y) };
		tileSprite.setScale(spriteScale);
	}
	void setSpritePosition(int posX, int posY)
	{ 
		position = sf::Vector2f{ static_cast<float>(posX * tileSize.x), static_cast<float>(posY * tileSize.y) };
		tileSprite.setPosition(position);	
	}

	MapTile* generateNewTile(int posX, int posY)
	{
		tileTexture = tilesTypeContainer.getTexturedTileRandomly();
		tileTexture.setRepeated(true);
		tileSprite.setTexture(tileTexture);
		setSpriteScale();
		setSpritePosition(posX, posY);

		return this;
	}
	const sf::Sprite& getSprite()
	{
		return tileSprite;
	}
	const sf::Vector2u getTileSize() { return tileSize; }
};
