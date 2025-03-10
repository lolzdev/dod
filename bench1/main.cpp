#include <iostream>
#include <cmath>
#include <vector>
#include "entity_extern.hpp"
#include "../prof.h"
#include "common.hpp"

#define ENTITIES 100000
#define TICKS 100

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

    void update()
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
};


void test_entities()
{
    static std::vector<Entity> entities;
    for (int i=0; i < ENTITIES; i++) {
        entities.push_back(Entity());
    }

    PROF_BEGIN(update_method)
    for (int t=0; t < TICKS; t++) {
        for (int i=0; i < ENTITIES; i++) {
            entities[i].update();
        }
    }
    PROF_END

    PROF_BEGIN(update_inline)
    for (int t=0; t < TICKS; t++) {
        for (int i=0; i < ENTITIES; i++) {
            auto entity = entities[i];

            if (entity.alive) {
                entity.position += vec3(0.0, -0.5, 0.0);
                auto tmp = entity.direction;
                tmp *= entity.speed;
                entity.position += tmp;
            }

            if (entity.health <= 0.0) {
                entity.alive = false;
            }
        }
    }
    PROF_END
}

void test_entities_ext()
{
    static std::vector<ext::Entity> entities;
    for (int i=0; i < ENTITIES; i++) {
        entities.push_back(ext::Entity());
    }

    PROF_BEGIN(update_method_ext)
    for (int t=0; t < TICKS; t++) {
        for (int i=0; i < ENTITIES; i++) {
            entities[i].update();
        }
    }
    PROF_END

    PROF_BEGIN(update_inline_ext)
    for (int t=0; t < TICKS; t++) {
        for (int i=0; i < ENTITIES; i++) {
            auto entity = entities[i];

            if (entity.alive) {
                entity.position += vec3(0.0, -0.5, 0.0);
                auto tmp = entity.direction;
                tmp *= entity.speed;
                entity.position += tmp;
            }

            if (entity.health <= 0.0) {
                entity.alive = false;
            }
        }
    }
    PROF_END
}

int main(void)
{
    test_entities();
    test_entities_ext();

    return 0;
}
