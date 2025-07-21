#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <stdbool.h>

#include "raylib.h"

#include "config.h"

enum team_type {
	TEAM_NONE = 0,
	TEAM_PLAYER,
	TEAM_ENEMY,
};

enum layer_type {
	LAYER_NONE = 0,
	LAYER_BACKGROUND,
	LAYER_FOREGROUND,
};

extern Vector2 positions[MAX_ENTITIES];
extern bool has_position[MAX_ENTITIES];

extern Vector2 velocities[MAX_ENTITIES];
extern bool has_velocity[MAX_ENTITIES];

extern float angles[MAX_ENTITIES];
extern bool has_angle[MAX_ENTITIES];

extern float speeds[MAX_ENTITIES];
extern bool has_speed[MAX_ENTITIES];

extern float lifetimes[MAX_ENTITIES];
extern bool has_lifetime[MAX_ENTITIES];

extern int damages[MAX_ENTITIES];
extern bool has_damage[MAX_ENTITIES];

extern enum team_type teams[MAX_ENTITIES];
extern bool has_team[MAX_ENTITIES];

extern Texture2D textures[MAX_ENTITIES];
extern bool has_texture[MAX_ENTITIES];

extern Vector2 custom_origins[MAX_ENTITIES];
extern bool has_custom_origin[MAX_ENTITIES];

extern float sprite_rotation_offsets[MAX_ENTITIES];
extern bool has_sprite_rotation_offset[MAX_ENTITIES];

extern enum layer_type layers[MAX_ENTITIES];
extern bool has_layer[MAX_ENTITIES];

extern bool has_input[MAX_ENTITIES];
extern bool has_mouse_angle[MAX_ENTITIES];
extern bool has_shooting[MAX_ENTITIES];
extern bool has_rounded_drawing[MAX_ENTITIES];
extern bool has_map_clamp[MAX_ENTITIES];

#endif
