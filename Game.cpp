#include "Game.h"

void Game::run()
{
   // window.setFramerateLimit(15);

    while (window.isOpen())
    {
        event.updateEvent(window);

        hero.heroMove();
        draw.draw(window);  
    }
}

void Game::load()
{
    loadWorld.attach(&draw);
    loadWorld.loadWorld();
    loadWorld.detach(&draw);   

    hero.attach(&draw);
    // hero.update();
    // hero.detach(&draw);
}
