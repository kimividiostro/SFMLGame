#include"State.hpp"
#include"IdleState.hpp"
#include"JumpState.hpp"
#include<iostream>

void JumpState::enter() {
	std::cout << "Entered 'Jump' State" << std::endl;
}

PlayerState* JumpState::input(sf::Keyboard::Key input) {
	if (input == sf::Keyboard::Left) {
		player->moveForce = player->MAX_MOVE_FORCE;
		player->direction = -1;
	}
	if (input == sf::Keyboard::Right) {
		player->moveForce = player->MAX_MOVE_FORCE;
		player->direction = 1;
	}
	return NULL;
}

PlayerState* JumpState::update(Player* player, float deltaTime) {
	player->shape.move(player->moveForce * player->direction * deltaTime, jumpForce * deltaTime);
	jumpForce += gravity;
	player->moveForce -= player->MOVE_FORCE_DECREMENT;
	if (player->moveForce < 0) {
		player->moveForce = 0;
	}
	std::cout << "Jump force: " << jumpForce << " " << " player y: " << player->shape.getPosition().y;
	if (player->shape.getPosition().y >= 300) {
		player->shape.setPosition(player->shape.getPosition().x, 300);
		return new IdleState(player);
	}
	return NULL;
}

void JumpState::exit() {
	std::cout << "Exited 'Jump' State" << std::endl;
}