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
		setScale(sf::Vector2i(800,100));
	}

	void loadTexture(const std::string& sprite)
	{
		if (!animatedTexture.loadFromFile(sprite))
		{
			throw TextureLoadExpection();
		}
	}

	void setTextureRect(const int verticalIndex, const int horizontalIndex, const int width, const int height)
	{
		animatedSprite.setTextureRect(sf::IntRect(verticalIndex * width, horizontalIndex * height, width, height));
	}

	void setSpritePosition(sf::Vector2f position)
	{
		animatedSprite.setPosition(position);
	}

	void setScale(sf::Vector2i size)
	{
		sf::Vector2f textureSize = sf::Vector2f{ animatedSprite.getLocalBounds().width, animatedSprite.getLocalBounds().height };
		sf::Vector2f spriteScale = sf::Vector2f{ static_cast<float>(size.x) / static_cast<float>(textureSize.x), static_cast<float>(size.y) / static_cast<float>(textureSize.y) };
		animatedSprite.setScale(spriteScale);
	}

	const sf::Sprite& getSprite() { return animatedSprite; }
};
