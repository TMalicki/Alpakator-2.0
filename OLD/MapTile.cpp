#include "MapTile.h"

void MapTile::setSpriteScale()
{
	sf::Vector2f textureSize = sf::Vector2f{ tileSprite.getLocalBounds().width, tileSprite.getLocalBounds().height };
	sf::Vector2f spriteScale = sf::Vector2f{ static_cast<float>(tileSize.x) / static_cast<float>(textureSize.x), static_cast<float>(tileSize.y) / static_cast<float>(textureSize.y) };
	tileSprite.setScale(spriteScale);
}

void MapTile::setSpritePosition(int posX, int posY)
{
	position = sf::Vector2f{ static_cast<float>(posX * tileSize.x), static_cast<float>(posY * tileSize.y) };
	tileSprite.setPosition(position);
}

void MapTile::loadTilesSettings(int posX, int posY)
{
	tileTexture.setRepeated(true);
	tileSprite.setTexture(tileTexture);
	setSpriteScale();
	setSpritePosition(posX, posY);
}

const MapTile& MapTile::generateNewTile(int posX, int posY)
{
	tileTexture = tilesTypeContainer.getTexturedTileRandomly();
	loadTilesSettings(posX, posY);

	return *this;
}

const MapTile& MapTile::generateNewTileButNotWalkable(int posX, int posY)
{
	tileTexture = tilesTypeContainer.getTexturedTileRandomlyButNotGrassType();
	loadTilesSettings(posX, posY);

	return *this;
}

const MapTile& MapTile::generateWalkableTile(int posX, int posY)
{
	tileTexture = tilesTypeContainer.getGrassTileTexture();
	loadTilesSettings(posX, posY);

	return *this;
}
