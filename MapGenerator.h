#pragma once
#include <iostream>
#include <vector>
#include "RandomNumberGenerator.h"

// that should be strategy pattern!!!

class MapGenerator
{
protected: //? is it necessary?
	const unsigned int tileAmountInWidth;
	const unsigned int tileAmountInHeight;
	std::vector<std::vector<int>> level;

private:
public:
	MapGenerator(const sf::Vector2u tileAmount)
		: tileAmountInWidth{ tileAmount.x }, tileAmountInHeight{ tileAmount.y }
	{
		generateMap();
	}

	void generateMap()
	{
		std::vector<int> temp{};
		for (size_t i = 0; i < tileAmountInWidth; i++)
		{
			temp.push_back(0);	
		}

		for (size_t j = 0; j < tileAmountInHeight; j++)
		{
			level.push_back(temp);
		}
	};

	
	virtual void generateDungeonWithAlgorithm() = 0;
	std::vector<std::vector<int>> getTilesToRender() { return level; };
};