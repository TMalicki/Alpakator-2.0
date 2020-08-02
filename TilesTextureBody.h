#pragma once
#include <SFML/Graphics.hpp>
#include "TileSettings.h"

class TilesTextureBody
{
protected:
	sf::RectangleShape tile; // here will be texture

public:
	TilesTextureBody()
	{
		tile.setOutlineThickness(-1);
		tile.setOutlineColor(sf::Color::Black);
	}
	virtual ~TilesTextureBody() {};

	virtual void setType() = 0;
	const sf::RectangleShape getTile() { return tile; }
};

