#pragma once

#include <SFML/Graphics.hpp>
#include "loadWorld.h"

class Draw : public ObserverInterface
{
private:
	std::vector<std::vector<sf::Sprite>> renderedMap;
	TilesTypesContainer container;
public:
	Draw() {};
	void draw(sf::RenderWindow&);

	virtual void updateMap(std::vector<std::vector<sf::Sprite>> renderedMap)
	{
		this->renderedMap = renderedMap;
	}
};