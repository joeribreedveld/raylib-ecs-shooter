#include "ecs/components.h"

/* Position */
Vector2 positions[MAX_ENTITIES];

bool has_position[MAX_ENTITIES];

/* Velocity */
Vector2 velocities[MAX_ENTITIES];

bool has_velocity[MAX_ENTITIES];

/* Speed */
float speeds[MAX_ENTITIES];

bool has_speed[MAX_ENTITIES];

/* Input */
bool has_input[MAX_ENTITIES];