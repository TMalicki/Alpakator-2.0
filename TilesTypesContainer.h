#pragma once

#include "RandomNumberGenerator.h"
#include "TileChosenTextureType.h"

//context class - user of strategy design pattern (TileTypes interface class)
class TilesTypesContainer
{
private:
	RandomNumberGenerator randomGenerator;
	std::vector<std::shared_ptr<TileChosenTextureType>> tiles;
public:
	//here should be added new tileType class (derived - not base class) if added
	TilesTypesContainer()
	{	
		add("GrassTile");
		add("WaterTile");
		add("BrickTile");
	}

	void add(std::string tileType)
	{
		tiles.push_back(std::make_shared<TileChosenTextureType>());
		if(tileType == "GrassTile") tiles.back()->setTextureType(std::make_shared<GrassTile>());
		else if (tileType == "BrickTile") tiles.back()->setTextureType(std::make_shared<BrickTile>());
		else if (tileType == "WaterTile") tiles.back()->setTextureType(std::make_shared<WaterTile>());
	}

	const sf::RectangleShape getTypeRandomly()
	{
		int tileNumber = randomGenerator.generateRandomInt(0, tiles.size() - 1);
		return tiles[tileNumber]->getTextureType();
	}
};
