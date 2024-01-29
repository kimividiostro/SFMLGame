#include"JumpState.hpp"
#include"IdleState.hpp"
#include"MovingState.hpp"
#include<iostream>


void IdleState::enter() {
	std::cout << "Entered 'Idle' State" << std::endl;
}

PlayerState* IdleState::input(sf::Keyboard::Key input) {
	if (input == sf::Keyboard::Space) {
		return new JumpState(player); 
	}
	if (input == sf::Keyboard::Left) {
		return new MovingState(player);
	}
	if (input == sf::Keyboard::Right) {
		return new MovingState(player);
	}
	return NULL;
}

PlayerState* IdleState::update(Player* player, float deltaTime) {
	std::cout << "Updating IdleState" << std::endl;
	return NULL;
}

void IdleState::exit() {
	std::cout << "Exited 'Idle' State" << std::endl;
}