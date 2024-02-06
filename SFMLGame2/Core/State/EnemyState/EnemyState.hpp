#pragma once
#include <Player.hpp>
#include "../../Enemy/Enemy.hpp"

class EnemyState {
public:
	virtual void enter(Enemy* enemy) = 0;
	virtual EnemyState* update(Enemy* enemy, const Player* player, float deltaTime) = 0;
	virtual void exit() = 0;
	virtual ~EnemyState() = default;
};