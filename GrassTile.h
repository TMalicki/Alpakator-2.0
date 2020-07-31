#pragma once

#include "TilesTypes.h"

class GrassTile : public TilesTypes
{
private:
	sf::Color tileType;
public:
	GrassTile(int tileWidth = 20, int tileHeight = 20) : TilesTypes(tileWidth, tileHeight), tileType{ sf::Color::Green } 
	{
		setType();
	};

	virtual void setType() { tile.setFillColor(tileType); }
};