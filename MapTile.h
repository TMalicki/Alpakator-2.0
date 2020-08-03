#pragma once

#include "TilesTypesContainer.h"

class MapTile
{
private:
	TilesTypesContainer tilesTypeContainer;

	sf::Vector2f position;
	sf::RectangleShape textureType;

	sf::Vector2u tileSize;
public:
	MapTile(sf::Vector2u tileSize) : position{}, textureType{}, tilesTypeContainer{}, tileSize{ tileSize } { }
	
	void setTextureSize() { textureType.setSize(sf::Vector2f{ static_cast<float>(tileSize.x), static_cast<float>(tileSize.y) }); }
	void setTexturePosition(int posX, int posY)
	{ 
		position = sf::Vector2f{ static_cast<float>(posX * tileSize.x), static_cast<float>(posY * tileSize.y) };
		textureType.setPosition(position);
	}

	const sf::RectangleShape addNewTile(int posX, int posY)
	{
		textureType = tilesTypeContainer.getTypeRandomly();
		setTexturePosition(posX, posY);
		setTextureSize();

		return textureType;
	}


};
