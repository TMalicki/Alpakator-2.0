#pragma once

#include "MapTile.h"
#include "MapGenerator.h"

class loadWorld
{
private:
	MapGenerator actualLevel;
	MapTile mapTile;

	std::vector<std::vector<sf::RectangleShape>> renderedMap;

public:
	loadWorld() : actualLevel{}, mapTile{} 
	{
		auto temp = actualLevel.getTilesToRender();
		std::vector<sf::RectangleShape> tempVector{};

		for (size_t i = 0; i < temp[0].size(); i++)
		{
			tempVector.push_back(sf::RectangleShape(sf::Vector2f{ 0,0 }));
		}

		for (size_t j = 0; j < temp.size(); j++)
		{
			renderedMap.push_back(tempVector);
		}
		generateWorld();
	};

	void generateWorld() 
	{
		std::vector<std::vector<int>> tilesToRender = actualLevel.getTilesToRender();

		for (size_t i = 0; i < tilesToRender.size(); i++)
		{
			for (size_t j = 0; j < tilesToRender[i].size(); j++)
			{
				if (tilesToRender[i][j] == 1) renderedMap[i][j] = mapTile.addNewTile(j, i);
			}
		}
	};

	std::vector<std::vector<sf::RectangleShape>> getRenderedMap() { return renderedMap; };
};