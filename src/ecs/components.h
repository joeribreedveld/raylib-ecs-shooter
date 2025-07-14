#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "raylib.h"

#define MAX_ENTITIES 1024

/* Position */
extern Vector2 positions[MAX_ENTITIES];

extern bool has_position[MAX_ENTITIES];

/* Velocity */
extern Vector2 velocities[MAX_ENTITIES];

extern bool has_velocity[MAX_ENTITIES];

/* Speed */
extern float speeds[MAX_ENTITIES];

extern bool has_speed[MAX_ENTITIES];

/* Input */
extern bool has_input[MAX_ENTITIES];

#endif