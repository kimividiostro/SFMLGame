#include"Enemy.hpp"
#include"EnemyState/EnemyIdleState.hpp"

Enemy::Enemy() : state(nullptr), shape(30.f) {
	this->state = new EnemyIdleState();
	this->state->enter(this);
	this->shape.setOrigin(30, 30);
	this->shape.setPosition(100, 300);
}

void Enemy::update(const Player* player, const float deltaTime) {
	auto newState = this->state->update(this, player, deltaTime);
	if (newState) {
		this->state->exit();
		delete this->state;
		this->state = newState;
		this->state->enter(this);
	}
}

Enemy::~Enemy() {
	delete this->state;
}