#pragma once

#include <SFML/Graphics.hpp>
#include "loadWorld.h"

class Draw : public ObserverInterface
{
private:
	std::vector<std::vector<std::shared_ptr<MapTile>>> renderedMap;
	sf::Sprite hero;
public:
	Draw() {};
	void draw(sf::RenderWindow&);

	virtual void updateMap(std::vector<std::vector<std::shared_ptr<MapTile>>>& renderedMap)
	{
		this->renderedMap = renderedMap;
	}
	virtual void updateHero(const sf::Sprite& hero) 
	{
		this->hero = hero;
	};
};