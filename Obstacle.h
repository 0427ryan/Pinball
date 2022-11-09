#pragma once

#include "MyVector.h"
#include "ball.h"

class Obstacle
{
	float radius;
	MyVector location = { 0, 0 };
public:
	Obstacle() = default;
	Obstacle(float x, float y, float r) :location({ x, y}), radius(r) {}

	bool isBump(Ball *ball);
	MyVector getLocation() { return this->location; }
	float getRadius() { return this->radius; }
};

