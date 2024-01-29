#include "Player.hpp"
#include "IdleState.hpp"

Player::Player() : state(nullptr), name("player1"), shape(30.f) {
	this->state = new IdleState(this);
	shape.setOrigin(0, 0);
	shape.setPosition(400, 300);
	shape.setFillColor(sf::Color::Green);
};

void Player::input(sf::Keyboard::Key input) {
	auto newState = this->state->input(input);
	if (newState) {
		delete this->state;
		this->state = newState;
	}
};

void Player::update(float deltaTime) {
	auto newState = this->state->update(this, deltaTime);
	if (newState) {
		this->state->exit();
		delete this->state;
		this->state = newState;
	}
};

Player::~Player() {
	if (state != nullptr) {
		delete state;
		state = nullptr;
	}
};