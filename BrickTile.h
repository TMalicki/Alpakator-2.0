#pragma once

#include "TilesTextureTypes.h"

class BrickTile : public TilesTextureTypes
{
private:
	sf::Color tileType;
public:
	BrickTile() : TilesTextureTypes(), tileType{ sf::Color(255,153,51) }
	{
		setType();
	};

	virtual void setType() { tile.setFillColor(tileType); }
};