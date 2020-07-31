#pragma once

#include <SFML/Graphics.hpp>
#include "loadWorld.h"

class Draw
{
private:
	loadWorld loadWorld;
public:
	Draw() {};
	void draw(sf::RenderWindow&);


};