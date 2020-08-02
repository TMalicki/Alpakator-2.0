#pragma once
#include "GrassTile.h"
#include "BrickTile.h"
#include "WaterTile.h"

class TileChosenTextureType
{
private:
	std::shared_ptr<TilesTextureBody> chosenTextureTypeForTile;
public:
	TileChosenTextureType() : chosenTextureTypeForTile{} {}

	void setTextureType(std::shared_ptr<TilesTextureBody> type) { chosenTextureTypeForTile = type; }

	const sf::RectangleShape getTextureType()
	{
		return chosenTextureTypeForTile->getTile();
	}
};
