#include "Game.h"


void Game::run()
{
    while (window.isOpen())
    {
        event.updateEvent(window);

        draw.draw(window);
    }
}
