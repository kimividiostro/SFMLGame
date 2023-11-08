#pragma once

#include<iostream>

class State {
public:
	virtual void enter() = 0;
	virtual std::shared_ptr<State> input() = 0;
	virtual std::shared_ptr<State> update(float deltaTime) = 0;
	virtual void exit() = 0;
	virtual ~State() = default;
};