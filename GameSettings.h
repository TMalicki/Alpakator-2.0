#pragma once

class GameSettings
{
private:
	unsigned int windowWidth;
	unsigned int windowHeight;


public:
	GameSettings(unsigned int width, unsigned int height) : windowHeight{ height }, windowWidth{ width } { }
};