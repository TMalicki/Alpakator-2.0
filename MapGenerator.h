#pragma once
#include <iostream>
#include <vector>

class MapGenerator
{
protected:
	const unsigned int tileAmountInWidth;
	const unsigned int tileAmountInHeight;
	std::vector<std::vector<int>> level;

public:
	MapGenerator(const sf::Vector2u tileAmount)
		: tileAmountInWidth { tileAmount.x }, tileAmountInHeight{ tileAmount.y } 
	{
		generateMap();
	}

	void generateMap()
	{
		std::vector<int> temp{};
		for (size_t i = 0; i < tileAmountInWidth; i++)
		{
			temp.push_back(1);	// procedural generated map here should be
		}

		for (size_t j = 0; j < tileAmountInHeight; j++)
		{
			level.push_back(temp);
		}
	};

	std::vector<std::vector<int>> getTilesToRender() { return level; };
};