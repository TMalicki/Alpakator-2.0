#pragma once

#include "TilesTextureBody.h"

class WaterTile : public TilesTextureBody
{
private:
	sf::Color tileType;
public:
	WaterTile() : TilesTextureBody(), tileType{ sf::Color::Blue }
	{
		setType();
	};

	virtual void setType() { tile.setFillColor(tileType); }
};