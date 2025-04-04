#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

sf::Font arialFont;

Vec2 windowSize = Vec2(800, 500);
sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "The Game game");

int score = 0;
bool hasLost = false;

sf::Clock enemySpawnTimer;

Player player = Player(Vec2{400, 450});
std::vector<Enemy> enemies;


void SpawnRandomEnemy() {
    Enemy newEnemy = Enemy(Vec2(std::rand() % 800, -100));
    enemies.push_back(newEnemy);
}

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
            if (enemies.size() > 0) {
                for (auto it = enemies.begin(); it != enemies.end(); it++) {
                    //remove enemy when at bottom of screen
                    if (it->GetPosition().y > windowSize.y) {
                        enemies.clear();
                        hasLost = true;
                        break;
                    }

                    //score point if colliding with player
                    if (it->GetPosition().Distance(player.GetPosition()) <= it->GetModel().GetRadius() + player.GetModel().GetRadius()) {
                        score += 1;
                        it = enemies.erase(it);
                        continue;
                    }

                    it->Move();
                    it->Draw(window);
                }
            }

            //draw score
            sf::Text scoreText{ "Score: " + std::to_string(score), arialFont, 36};
            window.draw(scoreText);
        }
        else {
            sf::Text loseText{ "You Lost!", arialFont, 52 };
            window.draw(loseText);
        }

        //spawn new enemy every few seconds
        float elaspedTime = enemySpawnTimer.getElapsedTime().asSeconds();
        if (elaspedTime >= 2.0f) {
            SpawnRandomEnemy();
            enemySpawnTimer.restart();
        }

        //display everything
        player.Draw(window);
        window.display();
    }
}