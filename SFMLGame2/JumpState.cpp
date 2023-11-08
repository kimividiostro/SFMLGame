#include"Sate.hpp"
#include<iostream>

class JumpState : public State {
public:
	void enter() override {
		std::cout << "Entered 'Jump' State" << std::endl;
	}

	std::shared_ptr<State> input() override {
		std::cout << "Input 'Jump' State" << std::endl;
		return NULL;
	}

	std::shared_ptr<State> update(float deltaTime) override {
		std::cout << "Update 'Jump' State" << std::endl;
		return NULL;
	}

	void exit() override {
		std::cout << "Exited 'Jump' State" << std::endl;
	}
};