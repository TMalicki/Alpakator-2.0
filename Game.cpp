#include "Game.h"


void Game::run()
{
    while (window.isOpen())
    {
        event.updateEvent(window);
        draw.draw(window);
    }
}

void Game::load()
{
    loadWorld.attach(std::shared_ptr<ObserverInterface>(&draw));
    loadWorld.loadWorld();
    loadWorld.detach(std::shared_ptr<ObserverInterface>(&draw));    // here is problem
}
