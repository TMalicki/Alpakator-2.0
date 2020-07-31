#pragma once
#include <iostream>
#include <vector>

class MapGenerator
{
protected:
	int tileAmountInWidth;
	int tileAmountInHeight;
	std::vector<std::vector<int>> level;

public:
	MapGenerator(int tileAmountInWidth = 50, int tileAmountInHeight = 30)
		: tileAmountInWidth { tileAmountInWidth }, tileAmountInHeight{ tileAmountInHeight } 
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