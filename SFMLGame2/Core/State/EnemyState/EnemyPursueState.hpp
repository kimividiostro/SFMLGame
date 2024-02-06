#pragma once
#include"EnemyState/EnemyState.hpp"

class EnemyPursueState : public EnemyState {
	void enter(Enemy* enemy) override;
	EnemyState* update(Enemy* enemy, const Player* player, float deltaTime) override;
	void exit() override;
};