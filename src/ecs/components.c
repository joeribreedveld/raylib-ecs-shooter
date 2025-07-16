#include "ecs/components.h"

Vector2 positions[MAX_ENTITIES];
bool has_position[MAX_ENTITIES];

Vector2 velocities[MAX_ENTITIES];
bool has_velocity[MAX_ENTITIES];

float angles[MAX_ENTITIES];
bool has_angle[MAX_ENTITIES];

float speeds[MAX_ENTITIES];
bool has_speed[MAX_ENTITIES];

float lifetimes[MAX_ENTITIES];
bool has_lifetime[MAX_ENTITIES];

int damages[MAX_ENTITIES];
bool has_damage[MAX_ENTITIES];

enum team_type teams[MAX_ENTITIES];
bool has_team[MAX_ENTITIES];

Texture2D textures[MAX_ENTITIES];
bool has_texture[MAX_ENTITIES];

Rectangle src_rects[MAX_ENTITIES];
bool has_src_rect[MAX_ENTITIES];

bool has_input[MAX_ENTITIES];
bool has_mouse_angle[MAX_ENTITIES];
bool has_shooting[MAX_ENTITIES];
