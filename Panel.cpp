#include "Panel.h"
#include <iostream>

void Panel::kick(Ball* ball) {
	Line l2 = { l.v1, ball->getLocation() - l.v1 };
	l2.reflect(ball);
	MyVector v = ball->getLocation() - l.v1;
	if (direction == COUNTERCLOCKWISE) {
		v = v.rotate({ 0, 1 });
	}
	else {
		v = v.rotate({ 0, -1 });
	}
	MyVector speed = v.normalize() * power;
	ball->setSpeed(ball->getSpeed() + speed);
}

void Panel::reflect(Ball* ball) {
	getLine().reflect(ball);
}

bool isBetween(MyVector v1, MyVector v2, MyVector v3) {
	float asin1 = asin(v1.sine());
	float asin2 = asin(v2.sine());
	float asin3 = asin(v3.sine());

	return asin1 < asin3 and asin3 < asin2 or
		asin1 > asin3 and asin3 > asin2;
}

bool Panel::isCatch(Ball* ball) {
	if (direction == CLOCKWISE) {
		MyVector v2 = (l.v2 - l.v1).rotate({ cos * cos, 1 });

		Line l2 = { l.v1, l.v1 + v2};
		if (l.isBump(ball) or l2.isBump(ball)) {
			return true;
		}
		MyVector v = ball->getLocation() - l.v1;
		if (v.length() < ball->getRadius() + l.length() and 
			isBetween(l.v2 - l.v1, l2.v2 - l.v1, v)) {
			return true;
		}
	}
	else {
		
		MyVector v2 = (l.v2 - l.v1).rotate({ cos * cos, -1 });

		Line l2 = { l.v1, l.v1 + v2 };
		if (l.isBump(ball) or l2.isBump(ball)) {
			return true;
		}
		MyVector v = ball->getLocation() - l.v1;
		if (v.length() < ball->getRadius() + l.length() and
			isBetween(l.v2 - l.v1, l2.v2 - l.v1, v)) {
			return true;
		}
	}
	return false;
	
}
bool Panel::isBump(Ball* ball) {
	return getLine().isBump(ball);
}
