#pragma once
#include <SFML/Graphics.hpp>
#include "MapGenerator.h"

enum class DirectionOfWalk { Up, Right, Down, Left };

class RandomWalkAlgorithm : public MapGenerator
{
private:
	DirectionOfWalk walkDirection;
	sf::Vector2i spawnPoint;
	sf::Vector2i actualCoord;
	RandomNumberGenerator randomNumber;
	
	sf::Vector2i upDirection;
	sf::Vector2i rightDirection;
	sf::Vector2i downDirection;
	sf::Vector2i leftDirection;

	sf::Vector2i randomDirection;
	sf::Vector2i lastDirection;

	unsigned int maxTunnels;
	unsigned int maxLength;
	unsigned int actualLength;
public:
	RandomWalkAlgorithm(const sf::Vector2u tileAmount) : MapGenerator(tileAmount), walkDirection{}, maxTunnels{ 20 }, maxLength{}, upDirection{ sf::Vector2i{0, -1} }
		, rightDirection{ sf::Vector2i{1, 0} }, downDirection{ sf::Vector2i{0, 1} }, leftDirection{ sf::Vector2i{-1, 0} }, randomDirection{}, lastDirection{}
		, actualLength{}, actualCoord{} {}

	void generateSpawnPointRandomly()
	{
		spawnPoint = sf::Vector2i{ (randomNumber.generateRandomInt(0, tileAmountInWidth - 1)), (randomNumber.generateRandomInt(0, tileAmountInHeight - 1)) };
	}

	void getWalkDirection()
	{
		do
		{
			auto temp = randomNumber.generateRandomInt(0, 3);
			switch (temp)
			{
			case 0:
			{
				walkDirection = DirectionOfWalk::Up;
				randomDirection = upDirection;
			}
			break;
			case 1:
			{
				walkDirection = DirectionOfWalk::Right;
				randomDirection = rightDirection;
			}
			break;
			case 2:
			{
				walkDirection = DirectionOfWalk::Down;
				randomDirection = downDirection;
			}
			break;
			case 3:
			{
				walkDirection = DirectionOfWalk::Left;
				randomDirection = leftDirection;
			}
			break;
			}
		} while (randomDirection == lastDirection || randomDirection == -lastDirection);
	}

	void getRandomMaxLength()
	{
		maxLength = randomNumber.generateRandomInt(1, tileAmountInWidth);
		actualLength = 0;
	}

	void moveInDirection(sf::Vector2i& startingPoint, sf::Vector2i direction)
	{
		//if (startingPoint.y > 0)
		//{
			startingPoint += direction;
		//}
	}

	bool checkBorderCollision()
	{
		//std::cout << "Line 87\n";
		if ((actualCoord.y <= 0 && randomDirection == upDirection)
			|| (actualCoord.y >= tileAmountInHeight - 1 && randomDirection == downDirection)
			|| (actualCoord.x >= tileAmountInWidth - 1 && randomDirection == rightDirection)
			|| (actualCoord.x <= 0 && randomDirection == leftDirection))
			return true;
		//std::cout << "Line 93\n";
	}

	void buildDungeonTunnel()
	{
		//actualCoord = spawnPoint;
		getWalkDirection();
		std::cout << "RandomDirection: " << randomDirection.x << " " << randomDirection.y << "\n";
		getRandomMaxLength();

		while (maxLength > actualLength)
		{
			//std::cout << "Line 108\n";
			if (checkBorderCollision() == true)
			{
			//	std::cout << "Line 112\n";
				break;
			//	std::cout << "Break\n";
			}
			else
			{
				level[actualCoord.y][actualCoord.x] = 1;
				moveInDirection(actualCoord, randomDirection);
				//std::cout << "Moved\n";
				actualLength++;
			}
			//std::cout << "Line 123\n";
		}

		if (actualLength >= 1)
		{
			//std::cout << "Line 128\n";
			lastDirection = randomDirection;
			maxTunnels--;
			//std::cout << "Tunnel finished\n";
		}
	}

	virtual void generateDungeonWithAlgorithm()
	{
		generateSpawnPointRandomly();
		actualCoord = spawnPoint;
		std::cout << "spawnPoint: " << spawnPoint.x << " " << spawnPoint.y << std::endl;
		while(maxTunnels >= 1) buildDungeonTunnel();


		for (size_t i = 0; i < level.size(); i++)
		{
			for (size_t j = 0; j < level[i].size(); j++)
			{
				std::cout << level[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "Dungeon finished\n";
	}
};