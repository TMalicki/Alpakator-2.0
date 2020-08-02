#pragma once

#include "TilesTextureTypes.h"

class GrassTile : public TilesTextureTypes
{
private:
	sf::Color tileType;
public:
	GrassTile() : TilesTextureTypes(), tileType{ sf::Color::Green }
	{
		setType();
	};

	virtual void setType() { tile.setFillColor(tileType); }
};