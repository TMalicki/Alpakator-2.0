#include "Game.h"

void Game::run()
{
    while (window.isOpen())
    {
        event.updateEvent(window);

        hero->update();
        gorgon->update();
        draw.draw(window);  
    }
    hero->detach(&draw);
}

void Game::load()
{
    loadWorld.attach(&draw);
    loadWorld.loadWorld();
    loadWorld.detach(&draw);   

    hero->attach(&draw);
    gorgon->attach(&draw);
}
