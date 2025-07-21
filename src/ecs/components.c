#include "ecs/components.h"
#include "config.h"

Vector2 positions[MAX_ENTITIES];
bool has_position[MAX_ENTITIES];

Vector2 velocities[MAX_ENTITIES];
bool has_velocity[MAX_ENTITIES];

Vector2 custom_origins[MAX_ENTITIES];
bool has_custom_origin[MAX_ENTITIES];

Texture2D textures[MAX_ENTITIES];
bool has_texture[MAX_ENTITIES];

enum team_type teams[MAX_ENTITIES];
bool has_team[MAX_ENTITIES];

float angles[MAX_ENTITIES];
bool has_angle[MAX_ENTITIES];

float speeds[MAX_ENTITIES];
bool has_speed[MAX_ENTITIES];

float lifetimes[MAX_ENTITIES];
bool has_lifetime[MAX_ENTITIES];

float sprite_rotation_offsets[MAX_ENTITIES];
bool has_sprite_rotation_offset[MAX_ENTITIES];

int damages[MAX_ENTITIES];
bool has_damage[MAX_ENTITIES];

enum layer_type layers[MAX_ENTITIES];
bool has_layer[MAX_ENTITIES];

bool has_input[MAX_ENTITIES];
bool has_mouse_angle[MAX_ENTITIES];
bool has_shooting[MAX_ENTITIES];
bool has_rounded_drawing[MAX_ENTITIES];
bool has_map_clamp[MAX_ENTITIES];
