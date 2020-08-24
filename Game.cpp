#include "Game.h"
#include "SpriteAnimation.h"

void Game::run()
{
    SpriteAnimation spriteAnimation("characterSprites/alpacaMove.png");
    spriteAnimation.setSpritePosition(sf::Vector2f(20.0f,0.0f));
    window.setFramerateLimit(15);

    while (window.isOpen())
    {
        spriteAnimation.moveRight();
        event.updateEvent(window);

        ///./////////////////////////////
        window.clear();

        draw.draw(window);  // clear and display methods inside are commented
        window.draw(spriteAnimation.getSprite());

        window.display();
        /////////////////////////////////
    }
}

void Game::load()
{
    loadWorld.attach(&draw);
    loadWorld.loadWorld();
    loadWorld.detach(&draw);   
}
