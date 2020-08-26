#pragma once

#include <iostream>
#include "../MapClasses/TilesTextureBody.h"

class GrassTile : public TilesTextureBody
{
private:

public:
	GrassTile() : TilesTextureBody() 
	{
		loadTexture();
	};

	virtual void loadTexture()
	{
		if (!tileSetTexture.loadFromFile("tilesTextures/grassTile.png"))
		{
			std::cout << "Texture was not loaded.";
		}
	}
};