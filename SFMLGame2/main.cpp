#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "IdleState.cpp"
#include "JumpState.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    sf::RectangleShape shape2(sf::Vector2f(50.f,50.f));
    shape2.setPosition(window.getSize().x - 200, window.getSize().y / 2);
    shape2.setFillColor(sf::Color::Red);

    sf::RectangleShape shape(sf::Vector2f(50.f, 50.f));
    float shapeSpeed = 900.f;
    shape.setOrigin(0, 0);
    shape.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    shape.setFillColor(sf::Color::Green);

    Player player;

    player.state = std::make_unique<IdleState>();
    player.name = "player1";
    
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        float deltaTime = clock.restart().asSeconds();
        std::cout << deltaTime << std::endl;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    shape.move(deltaTime * shapeSpeed * -1, 0);
                }
                if (event.key.code == sf::Keyboard::Right) {
                    shape.move(deltaTime * shapeSpeed, 0);
                }
                if (event.key.code == sf::Keyboard::Up) {
                    shape.move(0, deltaTime * shapeSpeed * -1);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    shape.move(0, deltaTime * shapeSpeed);
                }
                if (event.key.code == sf::Keyboard::Space) {
                    player.state = std::make_unique<JumpState>();
                }
            }
        }

        player.input();
        player.update(deltaTime);

        if (shape.getGlobalBounds().intersects(shape2.getGlobalBounds())) {
            // colided
        }

        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.display();
    }

    return 0;
}