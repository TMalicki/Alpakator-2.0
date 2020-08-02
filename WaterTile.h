#pragma once

#include "TilesTextureTypes.h"

class WaterTile : public TilesTextureTypes
{
private:
	sf::Color tileType;
public:
	WaterTile() : TilesTextureTypes(), tileType{ sf::Color::Blue }
	{
		setType();
	};

	virtual void setType() { tile.setFillColor(tileType); }
};