#include "Draw.h"

void Draw::draw(sf::RenderWindow& window)
{
	window.clear();

	auto temp = loadWorld.getRenderedMap();

	for (size_t i = 0; i < temp.size(); i++)
	{
		for (size_t j = 0; j < temp[i].size(); j++)
		{
			window.draw(temp[i][j]);
		}
	}

	window.display();
}
