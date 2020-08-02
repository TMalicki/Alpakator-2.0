#pragma once

#include <SFML/Graphics.hpp>
#include "loadWorld.h"

class Draw : public ObserverInterface
{
private:
	std::vector<std::vector<sf::RectangleShape>> renderedMap;
public:
	Draw() {};
	void draw(sf::RenderWindow&);

	virtual void updateMap(std::vector<std::vector<sf::RectangleShape>> renderedMap) 
	{
		this->renderedMap = renderedMap;
	}
};