#include <iostream>
#include <array>
#include <type_traits>
#include "prof.h"
#include "common.hpp"
#include "entity_extern.hpp"

#define ENTITIES 100000
#define TICKS 100

class Entity {
public:
    Entity() : position(0.0,0.0,0.0), direction(0.0,0.0,0.0), speed(5.0), health(100.0),alive(true)  {}

    vec3 position;
    vec3 direction;
    double speed;
    double health;
    bool alive;

    inline void update()
    {
        if (alive) {
            position += vec3(0.0, -0.5, 0.0);
            auto tmp = direction;
            tmp *= speed;
            position += tmp;
        }

        if (health <= 0.0) {
            alive = false;
        }
    }
};


void test_entities()
{
	std::cout << std::is_standard_layout<Entity>::value << std::endl;
    static std::array<Entity,ENTITIES> entities;


    PROF_BEGIN(update_method)
    for (int t=0; t < TICKS; t++) {
        for (auto & entity : entities) {
            entity.update();
        }
    }
    PROF_END

    PROF_BEGIN(update_inline)
    for (int t=0; t < TICKS; t++) {
        for (auto& entity : entities) {
            if (entity.alive) {
                entity.position += vec3(0.0, -0.5, 0.0);
                auto& tmp = entity.direction;
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
    static std::array<ext::Entity,ENTITIES> entities;

    PROF_BEGIN(update_method_ext)
    for (int t=0; t < TICKS; t++) {
        for (auto & entity : entities) {
            entity.update();
        }
    }
    PROF_END

    PROF_BEGIN(update_inline_ext)
    for (int t=0; t < TICKS; t++) {
        for (auto & entity : entities) {
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

int main()
{
    test_entities();
    test_entities_ext();

    return 0;
}
