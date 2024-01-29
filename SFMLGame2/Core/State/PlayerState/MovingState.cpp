#include "MovingState.hpp"
#include "Player.hpp";
#include "IdleState.hpp"

void MovingState::enter() {
	std::cout << "Entered moving state" << std::endl;
}

PlayerState* MovingState::input(sf::Keyboard::Key key) {
	std::cout << "Handling MovingState input" << std::endl;
	if (key == sf::Keyboard::Space) {
		return new JumpState(player);
	}
	if (key == sf::Keyboard::Left) {
		player->moveForce = player->MAX_MOVE_FORCE; 
		player->direction = -1;
	}
	if (key == sf::Keyboard::Right) {
		player->moveForce = player->MAX_MOVE_FORCE;
		player->direction = 1;
	} 

	return NULL;
}

PlayerState* MovingState::update(Player* player, float deltaTime) {
	std::cout << "Updating MovingState" << std::endl;
	if (player->moveForce < 0) {
		return new IdleState(player);
	}
	player->shape.move(player->moveForce * deltaTime * player->direction, 0);
	player->moveForce -= player->MOVE_FORCE_DECREMENT;

	return NULL;
}

void MovingState::exit() {
	player->moveForce = 0;
}