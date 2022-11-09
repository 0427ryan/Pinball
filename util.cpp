#include "util.h"

void do_reflect(Ball* b, Obstacle* o) {
	b->setSpeed(b->getSpeed().mirror(b->getLocation() - o->getLocation()));
}
