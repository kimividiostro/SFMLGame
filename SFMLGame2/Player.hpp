#pragma once
#include "Sate.hpp"

class Player {
public:
	std::shared_ptr<State> state;
	std::string name;

	void input() {
		auto newState = this->state.get()->input();
		if (newState) {
			this->state = newState;
		}
	}

	void update(float deltaTime) {
		auto newState = this->state.get()->update(deltaTime);
		if (newState) {
			this->state = newState;
		}
	}
};