#pragma once

#include "GrassTile.h"

class TilesTypesContainer
{
private:
	std::vector<std::shared_ptr<TilesTypes>> tiles;
public:
	TilesTypesContainer()
	{
		tiles.push_back(std::make_shared<GrassTile>());
	}

	sf::RectangleShape getType(std::string type)
	{
		if (type == "grass")
			return tiles[0]->getType();
	}
};