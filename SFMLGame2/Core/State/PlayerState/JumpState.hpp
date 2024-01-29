#pragma once

#include"PlayerState.hpp"
#include<iostream>

class JumpState : public PlayerState {
	Player* player;
	float time = 0;
	float jumpForce = -250.f;
	float gravity = 10.f;
public:
	JumpState(Player* player) : PlayerState() {
		this->player = player;
	};

	void enter() override;

	PlayerState* input(sf::Keyboard::Key input);

	PlayerState* update(Player* player, float deltaTime) override;

	void exit() override;
};