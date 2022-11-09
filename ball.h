
#pragma once


#include "MyVector.h"

class Ball
{
    float radius;
    MyVector location = {0, 0};
    MyVector speed = {0, 0};
public:
    Ball() = default;
    ~Ball() = default;
    MyVector getSpeed() { return speed; };
    MyVector getLocation(){return location;}
    float getRadius() { return radius; }
    void setSpeed(MyVector speed){this->speed = speed;}
    void setLocation(MyVector location){this->location = location;}
    void setRadius(float radius) { this->radius = radius; }
};