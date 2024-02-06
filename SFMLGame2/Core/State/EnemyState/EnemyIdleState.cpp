#include"EnemyIdleState.hpp"
#include"EnemyPursueState.hpp"

void EnemyIdleState::enter(Enemy* enemy) {
	enemy->shape.setFillColor(sf::Color::Yellow);
}

EnemyState* EnemyIdleState::update(Enemy* enemy, const Player* player, float deltaTime) {
	auto distanceToPlayerX = abs(player->shape.getPosition().x - enemy->shape.getPosition().x);
	//std::cout << "Updating enemy idle state. Distance to player: " << distanceToPlayerX << std::endl;
	if (distanceToPlayerX < 50) {
		std::cout << "Player in range";
		return new EnemyPursueState();
	}

	return NULL;
}

void EnemyIdleState::exit() {

}