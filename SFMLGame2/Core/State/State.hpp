#pragma once

class State {
public:
	virtual void enter() = 0;
	virtual State* input(char input) = 0;
	virtual State* update(float deltaTime) = 0;
	virtual void exit() = 0;
	virtual ~State() = default;
};