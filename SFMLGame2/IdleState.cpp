#include "Sate.hpp"
#include<iostream>
#include "Player.hpp"

class IdleState : public State {
public:
	IdleState() : State() {}

	void enter() override {
		std::cout << "Entered 'Idle' State" << std::endl;
	}

	std::shared_ptr<State> input() override {
		std::cout << "Input 'Idle' State" << std::endl;
		return NULL;
	}

	std::shared_ptr<State> update(float deltaTime) override {
		std::cout << "Update 'Idle' State" << std::endl;
		return NULL;
	}

	void exit() override {
		std::cout << "Exited 'Idle' State" << std::endl;
	}
};