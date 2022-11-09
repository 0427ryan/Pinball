#include "Line.h"
#include <iostream>

bool Line::isBump(Ball* b) {
	MyVector v3 = v2 - v1;
	MyVector location = b->getLocation();
	if (v3.cross(v2 - location) < 0 || v3.cross(location - v1) < 0) {
		float distance = std::max((v1 - location).length(), (v2 - location).length());
		return distance < b->getRadius();
	}
	
	v3 = v3.normalize();
	
	MyVector v4 = v2 - location;
	float distance_square = v4.length() * v4.length() - v4.cross(v3) * v4.cross(v3);
	return distance_square < b->getRadius()* b->getRadius();
}

void Line::reflect(Ball* b) {
	MyVector v3 = v2 - v1;
	b->setSpeed(b->getSpeed().mirror(v3.rotate({ 0, 1 })));
}
float Line::length() {
	return (v1 - v2).length();
}