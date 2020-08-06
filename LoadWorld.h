#pragma once

#include "MapGenerator.h"
#include "MapTile.h"
#include "GameSettings.h"
#include "SubjectInterface.h"
#include "ObserverInterface.h"

class LoadWorld : public SubjectInterface
{
private:
	MapGenerator actualLevel;
	MapTile mapTile;

	std::vector<std::vector<MapTile*>> mapTiles;
	std::vector<ObserverInterface*> listObserver;
public:
	LoadWorld(std::shared_ptr<GameSettings> gameSettingsPtr) : actualLevel{ gameSettingsPtr->getTileAmount() }, mapTile{ gameSettingsPtr->getTileSize() }
	{ };
	virtual ~LoadWorld() {};

	void loadWorld()
	{
		prepareTheWorld();
		generateWorld();
	}

	void prepareTheWorld()
	{
		auto temp = actualLevel.getTilesToRender();
		std::vector<MapTile*> tempTiles{};

		for (size_t i = 0; i < temp.size(); i++)
		{
			mapTiles.push_back(tempTiles);
			for (size_t j = 0; j < temp[i].size(); j++)
			{
				mapTiles[i].push_back(new MapTile(mapTile.getTileSize()));
			}
		}
	}

	void generateWorld() 
	{
		std::vector<std::vector<int>> tilesToRender = actualLevel.getTilesToRender();

		for (size_t i = 0; i < tilesToRender.size(); i++)
		{
			for (size_t j = 0; j < tilesToRender[i].size(); j++)
			{
				if (tilesToRender[i][j] == 1)
				{
					mapTiles[i][j]->generateNewTile(j, i);
				}
			}
		}
		notify();
	};

	// observer design pattern methods
	
	virtual void attach(ObserverInterface* observer) { listObserver.push_back(observer); };
	virtual void detach(ObserverInterface* observer) 
	{ 
		auto iterator = std::find(listObserver.begin(), listObserver.end(), observer);
		if(iterator != listObserver.end())
			listObserver.erase(iterator);
	}
	virtual void notify() { std::for_each(listObserver.begin(), listObserver.end(), [&](ObserverInterface* observer) { observer->updateMap(mapTiles); }); };
	
};