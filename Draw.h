#pragma once

#include <SFML/Graphics.hpp>
#include "MapClasses/LoadWorld.h"

class Draw : public ObserverInterface
{
private:
	std::vector<std::vector<std::shared_ptr<MapTile>>> renderedMap;
	sf::Sprite CreaturesInterface;
public:
	Draw() {};
	void draw(sf::RenderWindow&);

	virtual void updateMap(std::vector<std::vector<std::shared_ptr<MapTile>>>& renderedMap)
	{
		this->renderedMap = renderedMap;
	}
	virtual void updateCreatures(const sf::Sprite& CreaturesInterface) 
	{
		this->CreaturesInterface = CreaturesInterface;
	};
};