#pragma once
#include <SFML/Graphics.hpp>

class TilesTextureTypes
{
protected:
	sf::RectangleShape tile; // here will be texture
private:
	const int tileWidth;
	const int tileHeight;


public:
	TilesTextureTypes(int tileWidth = 40, int tileHeight = 40)
		: tile(sf::Vector2f{ static_cast<float>(tileWidth), static_cast<float>(tileHeight) }), tileWidth{ tileWidth }, tileHeight{ tileHeight } 
	{
		tile.setOutlineThickness(-1);
		tile.setOutlineColor(sf::Color::Black);
	}
	virtual ~TilesTextureTypes() {};

	virtual void setType() = 0;
	const sf::RectangleShape getTile() { return tile; }
};