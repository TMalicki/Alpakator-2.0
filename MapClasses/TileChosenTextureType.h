#pragma once
#include "../MapClasses/GrassTile.h"
#include "../MapClasses/BrickTile.h"
#include "../MapClasses/WaterTile.h"

class TileChosenTextureType
{
private:
	std::shared_ptr<TilesTextureBody> chosenTextureTypeForTile;
public:
	TileChosenTextureType() : chosenTextureTypeForTile{} {}

	void setTextureType(const std::shared_ptr<TilesTextureBody>& type) { chosenTextureTypeForTile = type; }
	const sf::Texture& getTexturedTile() { return chosenTextureTypeForTile->getTexturedTile(); }
};
