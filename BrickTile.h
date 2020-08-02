#pragma once

#include "TilesTextureBody.h"

class BrickTile : public TilesTextureBody
{
private:
	sf::Color tileType;
public:
	BrickTile() : TilesTextureBody(), tileType{ sf::Color(255,153,51) }
	{
		setType();
	};

	virtual void setType() { tile.setFillColor(tileType); }
};