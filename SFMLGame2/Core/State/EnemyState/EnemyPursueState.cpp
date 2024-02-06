#include"EnemyPursueState.hpp"
#include"EnemyIdleState.hpp"

void EnemyPursueState::enter(Enemy* enemy) {
	enemy->shape.setFillColor(sf::Color::Red);
}

EnemyState* EnemyPursueState::update(Enemy* enemy, const Player* player, const float deltaTime) {
	float distanceToPlayerX = enemy->shape.getPosition().x - player->shape.getPosition().x;
	std::cout << distanceToPlayerX << std::endl;
	if (abs(distanceToPlayerX) > 100) {
		return new EnemyIdleState();
	}

	int direction = distanceToPlayerX < 0 ? 1 : -1;
	enemy->shape.move(150 * direction * deltaTime, 0);

	return NULL;
}

void EnemyPursueState::exit() {

}