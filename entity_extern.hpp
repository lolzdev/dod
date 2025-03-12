#pragma once

#include "common.hpp"

namespace ext {

class Entity {
public:
    Entity() : position(0.0,0.0,0.0), direction(0.0,0.0,0.0), speed(5.0), health(100.0),alive(true) {}

    vec3 position;
    vec3 direction;
    double speed;
    double health;
    bool alive;

    void update();
};

}
