#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "CustomTime.h"

sf::Font arialFont;

Vec2 windowSize = Vec2(800, 500);
sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "The Game game");

//score and difficulty
int score = 0;
sf::Text scoreText{ "Score: " + std::to_string(score), arialFont, 28 };
float difficulty = 1;

//game objects
GameObject player{Vec2(400, 400), 30};

std::vector<GameObject> enemies;

bool hasLost = false;

//time variables
CustomTime* customTime = CustomTime::GetInstance();

sf::Clock enemySpawnTimer;
sf::Clock deltaClock;
float deltaTime = 0;

void AddRandomEnemy() {
    float randomX = (rand() % 800);
    GameObject gEnemy = { Vec2(randomX, -100), 30 };
    Vec2 force = (rand() % 2) == 1 ? Vec2(-2.0f, 1.0f) : Vec2(-2.0f, 1.0f);
    gEnemy.GetRigidbody().SetForce(force * 1000);
    enemies.push_back(gEnemy);
}

//function that contains all game logic
void Game() {
    //spawns enemy every few seconds based on difficulty
    float elapsedTime = enemySpawnTimer.getElapsedTime().asSeconds();
    if (elapsedTime >= (1.5f / difficulty + 0.56f)) {
        AddRandomEnemy();
        enemySpawnTimer.restart();
        difficulty = difficulty * 1.008f;
    }

    Rigidbody& rb = player.GetRigidbody();

    //player movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rb.SetForce(Vec2(-1, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rb.SetForce(Vec2(1, 0));
    }

    if (rb.GetPosition().x + player.GetModel().GetRadius() >= window.getSize().x) {
        rb.SetPosition(Vec2(windowSize.x - player.GetModel().GetRadius(), rb.GetPosition().y));
    }
    if (rb.GetPosition().x - player.GetModel().GetRadius() <= 0) {
        rb.SetPosition(Vec2(player.GetModel().GetRadius(), rb.GetPosition().y));
    }

    rb.UpdatePosition();

    //updates enemies
    std::vector<GameObject>::iterator i = enemies.begin();
    while (i != enemies.end()) {
        Rigidbody& enemyRb = i->GetRigidbody();
        i->Draw(window);
        bool deleteEnemy = false;

        //check collision with player
        if (enemyRb.GetPosition().Distance(rb.GetPosition()) <= i->GetModel().GetRadius() + player.GetModel().GetRadius()) {
            deleteEnemy = true;
            score++;
            scoreText.setString("Score: " + std::to_string(score));
        }

        //check wall collisions and invert x force
        if (enemyRb.GetPosition().x + i->GetModel().GetRadius() >= window.getSize().x) {
            enemyRb.SetVelocity(Vec2(-enemyRb.GetVelocity().x, enemyRb.GetVelocity().y));
            enemyRb.SetPosition(Vec2(windowSize.x - i->GetModel().GetRadius(), enemyRb.GetPosition().y));
        }
        if (enemyRb.GetPosition().x - i->GetModel().GetRadius() <= 0) {
            enemyRb.SetVelocity(Vec2(-enemyRb.GetVelocity().x, enemyRb.GetVelocity().y));
            enemyRb.SetPosition(Vec2(i->GetModel().GetRadius(), enemyRb.GetPosition().y));
        }

        //delete enemy when under bottom of screen
        if (enemyRb.GetPosition().y - i->GetModel().GetRadius() >= windowSize.y) {
            deleteEnemy = true;
            hasLost = true;
        }

        if (deleteEnemy) {
            i = enemies.erase(i);
            continue;
        }

        enemyRb.UpdatePosition();
        i++;
    }

    //draws the player
    player.Draw(window);

    window.draw(scoreText);
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

        //updates deltatime
        customTime->Update();
    }
}