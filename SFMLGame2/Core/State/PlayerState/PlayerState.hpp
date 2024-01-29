#pragma once
#include"SFML/Window/Keyboard.hpp"

class Player;

class PlayerState {
public:
	virtual void enter() = 0;

	virtual PlayerState* input(sf::Keyboard::Key key) = 0; 

	virtual PlayerState* update(Player* player, float deltaTime) = 0;

	virtual void exit() = 0;

	virtual ~PlayerState() = default;
}; 