#pragma once

#include <SFML/Graphics.hpp>

class TilesTypes
{
protected:
	sf::RectangleShape tile;
private:
	const int tileWidth;
	const int tileHeight;

public:
	TilesTypes(int tileWidth, int tileHeight)
		: tile(sf::Vector2f{ static_cast<float>(tileWidth), static_cast<float>(tileHeight) }), tileWidth{ tileWidth }, tileHeight{ tileHeight } 
	{
		tile.setOutlineThickness(-2);
		tile.setOutlineColor(sf::Color::Black);
	}
	virtual ~TilesTypes() {};

	virtual void setType() = 0;
	sf::RectangleShape getType() { return tile; }
};