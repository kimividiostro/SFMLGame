#pragma once
#include <iostream>
#include "SFML/Window/Keyboard.hpp"
#include "PlayerState.hpp"
#include <SFML/System/Vector2.hpp>
#include "SFML/Graphics.hpp"

class Player {
public:
	PlayerState* state;
	std::string name;
	sf::CircleShape shape;
	float moveForce = 0;
	short direction = 1;
	const float MAX_MOVE_FORCE = 200.f;
	const float MOVE_FORCE_DECREMENT = 10.f;

	Player();
	~Player();

	void input(sf::Keyboard::Key input);

	void update(float deltaTime);
};