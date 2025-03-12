#include "entity_extern.hpp"

namespace ext {

void Entity::update()
{
    if (alive) {
        position += vec3(0.0, -0.5, 0.0);
        auto &tmp = direction;
        tmp *= speed;
        position += tmp;
    }

    if (health <= 0.0) {
        alive = false;
    }
}

}
