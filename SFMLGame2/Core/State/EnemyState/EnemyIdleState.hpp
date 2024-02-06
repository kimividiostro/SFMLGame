#pragma once

#include"EnemyState.hpp"
#include"iostream"

class EnemyIdleState : public EnemyState {
	void EnemyState::enter(Enemy* enemy) override;

	EnemyState* EnemyState::update(Enemy* enemy, const Player* player, float deltaTime) override;

	void EnemyState::exit() override;
};