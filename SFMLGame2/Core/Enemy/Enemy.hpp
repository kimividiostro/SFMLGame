#pragma once

#include"SFML/Main.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics.hpp"
#include"Player.hpp"
//#include"EnemyState/EnemyState.hpp"

class EnemyState;

class Enemy {
public:
	sf::CircleShape shape;
	EnemyState* state;

	void update(const Player* player, const float deltaTime);

	Enemy();
	~Enemy();
};