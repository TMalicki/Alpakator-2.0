#pragma once
#include "GrassTile.h"
#include "BrickTile.h"
#include "WaterTile.h"

class TileChosenTextureType
{
private:
	std::shared_ptr<TilesTextureTypes> chosenTextureTypeForTile;
public:
	TileChosenTextureType() : chosenTextureTypeForTile{} {}

	void setTextureType(std::shared_ptr<TilesTextureTypes> type) { chosenTextureTypeForTile = type; }

	const sf::RectangleShape getTextureType()
	{
		return chosenTextureTypeForTile->getTile();
	}
};
