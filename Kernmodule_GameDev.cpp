#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vec2.h";

sf::Font arialFont;

Vec2 windowSize = Vec2(800, 500);
sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "The Game game");

bool hasLost = false;

//function that contains all game logic
void Game() {

}

int main()
{
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

        //update the game if the player has not lost, else display end screen
        if (!hasLost) {
            Game();
        }
        else {
            sf::Text loseText{ "You Lost!", arialFont, 52 };
            window.draw(loseText);
        }

        //display everything
        window.display();
    }
}