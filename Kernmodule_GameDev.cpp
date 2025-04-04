#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

sf::Font arialFont;

Vec2 windowSize = Vec2(800, 500);
sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "The Game game");

bool hasLost = false;

GameObject player(Vec2{400,300}, 30);

int main()
{
    window.setFramerateLimit(30);

    //load font
    if (!arialFont.loadFromFile("arial.ttf"));

    //sets random seed
    srand(time(NULL));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        //clears screen
        window.clear(sf::Color::Black);

        //update the game if the player has not lost
        if (!hasLost) {

            //update player

            //update enemies
        }
        else {
            sf::Text loseText{ "You Lost!", arialFont, 52 };
            window.draw(loseText);
        }

        //display everything
        player.Draw(window);
        window.display();
    }
}