#pragma once

#include "TilesTextureBody.h"

class GrassTile : public TilesTextureBody
{
private:
	sf::Color tileType;
public:
	GrassTile() : TilesTextureBody(), tileType{ sf::Color::Green }
	{
		setType();
	};

	virtual void setType() { tile.setFillColor(tileType); }
};