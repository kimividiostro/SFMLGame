#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "IdleState.hpp"
#include "JumpState.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    Player player;
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
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.input(sf::Keyboard::Right);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.input(sf::Keyboard::Left);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.input(sf::Keyboard::Space);
        }

        player.update(deltaTime);

        window.clear();
        window.draw(player.shape);
        window.display();
    }

    return 0;
}