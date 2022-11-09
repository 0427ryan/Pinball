#include "Obstacle.h"


bool Obstacle::isBump(Ball *ball) {
	return (this->location - ball->getLocation()).length() <
		  (this->radius + ball->getRadius());
}

