#include "entity_extern.hpp"

#include <iostream>
#include <cmath>
#include <vector>
#include "entity_extern.hpp"

namespace ext {

void Entity::update()
{
    if (this->alive) {
        this->position += vec3(0.0, -0.5, 0.0);
        auto tmp = this->direction;
        tmp *= this->speed;
        this->position += tmp;
    }

    if (this->health <= 0.0) {
        this->alive = false;
    }
}

}
