#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"

sf::Font arialFont;

Vec2 windowSize = Vec2(800, 500);
sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "The Game game");

bool hasLost = false;

Player player = Player(Vec2{400, 450});

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
            if (player.GetPosition().x + player.GetModel().GetRadius() >= windowSize.x) {
                player.SetMoveForce(player.GetMoveForce() * -1);
            }
            if (player.GetPosition().x - player.GetModel().GetRadius() < 0) {
                player.SetMoveForce(player.GetMoveForce() * -1);
            }
            player.Move();

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