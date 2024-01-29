#pragma once

#include<iostream>
#include "Player.hpp"

class IdleState : public PlayerState {
	Player* player;
public:
	IdleState(Player* player) : PlayerState() {
		this->player = player;
	}

	void enter() override;

	PlayerState* input(sf::Keyboard::Key input) override;

	PlayerState* update(Player* player, float deltaTime) override;

	void exit() override;
};