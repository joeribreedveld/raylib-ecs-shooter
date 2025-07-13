#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "raylib.h"

#define MAX_ENTITIES 1000

extern Vector2 positions[MAX_ENTITIES];

extern bool has_position[MAX_ENTITIES];

extern Vector2 velocities[MAX_ENTITIES];

extern bool has_velocity[MAX_ENTITIES];

extern bool has_input[MAX_ENTITIES];

#endif