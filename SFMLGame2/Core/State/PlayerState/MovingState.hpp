#pragma once
#include "PlayerState.hpp"
#include"JumpState.hpp"

class MovingState : public PlayerState {
	Player* player;
public:
	MovingState(Player* player) : PlayerState() {
		this->player = player;
	}

	void enter();

	PlayerState* input(sf::Keyboard::Key key);

	PlayerState* update(Player* player, float deltaTime);

	void exit();

	~MovingState() {}
};