#pragma once

#include "common.hpp"

namespace ext {

class Entity {
public:
    Entity() {
        this->position = vec3(0.0, 0.0, 0.0);
        this->direction = vec3(0.0, 0.0, 0.0);
        this->speed = 5.0;
        this->health = 100.0;
        this->alive = true;
    }

    vec3 position;
    vec3 direction;
    double speed;
    double health;
    bool alive;

    void update();
};

}
