#include <stdio.h>
#include <stdint.h>
#include "prof.h"

#define ENTITIES 100000
#define TICKS 100

typedef struct vec3 {
    double e[3];
} vec3;

inline static vec3 vec3_new()
{
    vec3 n = {.e = {0.0, -0.5, 0.0}};
    return n;
}

inline static vec3 vec3_sum(vec3 a, vec3 b)
{
    vec3 result = a;
    result.e[0] += b.e[0];
    result.e[1] += b.e[1];
    result.e[2] += b.e[2];
    return result;
}

inline static vec3 vec3_mul(vec3 a, double b)
{
    vec3 result = a;
    result.e[0] *= b;
    result.e[1] *= b;
    result.e[2] *= b;
    return result;
}

typedef struct entity {
    vec3 position;
    vec3 direction;
    double speed;
    double health;
    uint8_t alive;
} entity;

void update_entity(entity *e)
{
    if (e->alive) {
        vec3 t1 = vec3_new();
        e->position = vec3_sum(e->position, t1);
        vec3 t2 = e->direction;
        t2 = vec3_mul(t2, e->speed);
        e->position = vec3_sum(e->position, t2);
    }

    if (e->health <= 0.0) {
        e->alive = 0;
    }
}

void test_entities()
{
 // sogus
    entity entities[ENTITIES] = {0};

    PROF_BEGIN(update_method)
    for (int t=0; t < TICKS; t++) {
        for (int i=0; i < ENTITIES; i++) {
            update_entity(&entities[i]);
        }
    }
    PROF_END

    PROF_BEGIN(update_inline)
    for (int t=0; t < TICKS; t++) {
        for (int i=0; i < ENTITIES; i++) {
            entity e = entities[i];

            if (e.alive) {
                vec3 t1 = vec3_new();
                e.position = vec3_sum(e.position, t1);
                vec3 t2 = e.direction;
                t2 = vec3_mul(t2, e.speed);
                e.position = vec3_sum(e.position, t2);
            }

            if (e.health <= 0.0) {
                e.alive = 0;
            }
        }
    }
    PROF_END
}

int main(void)
{
    test_entities();
    return 0;
}
