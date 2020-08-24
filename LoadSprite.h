#pragma once
#include "SFML/Graphics.hpp"
#include "TextureLoadExpection.h"

class LoadSprite
{
private:
	sf::Texture animatedTexture;
	sf::Sprite animatedSprite;
public:
	LoadSprite(const std::string& spriteLocalization) : animatedTexture{}, animatedSprite{} { loadSprite(spriteLocalization); };

	void loadSprite(const std::string& sprite)
	{
		try
		{
			loadTexture(sprite);
		}
		catch (const TextureLoadExpection& ex)
		{
			std::cerr << "Error - Unable to load texture. Wrong Texture localization. (LoadSprite.h class)\n";
		}
		animatedSprite.setTexture(animatedTexture);
	}

	void loadTexture(const std::string& sprite)
	{
			if (!animatedTexture.loadFromFile(sprite))
			{
				throw TextureLoadExpection();
			}
	}
};