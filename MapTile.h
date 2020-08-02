#pragma once

#include "TilesTypesContainer.h"

class MapTile
{
private:
	TilesTypesContainer tilesTypeContainer;

	sf::Vector2i position;
	sf::RectangleShape textureType;

public:
	MapTile() : position{}, textureType{}, tilesTypeContainer{} {}

	const sf::RectangleShape addNewTile(int posX, int posY)
	{
		textureType = tilesTypeContainer.getTypeRandomly();

		position = sf::Vector2i{ posX * 40/* + tileWidth */, posY * 40/* + tileHeight */};
		textureType.setPosition(position.x, position.y);
	

		return textureType;
	}


};
