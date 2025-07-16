#include "ecs/components.h"
#include "ecs/entity.h"
#include "raylib.h"
#include <math.h>

void render_layer(enum layer_type layer)
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i] || !has_angle[i]) {
			continue;
		}

		if (layers[i] != layer) {
			continue;
		}

		float rotation = angles[i];

		Rectangle src = { 0, 0, textures[i].width, textures[i].height };

		Rectangle dest = { positions[i].x, positions[i].y,
				   textures[i].width, textures[i].height };

		Vector2 origin = { textures[i].width / 2.0f,
				   textures[i].height / 2.0f };

		if (has_sprite_rotation_offset[i]) {
			rotation += sprite_rotation_offsets[i];
		}

		if (has_rounded_drawing[i]) {
			dest.x = (int)roundf(dest.x);
			dest.y = (int)roundf(dest.y);
		}

		if (has_custom_origin[i]) {
			origin = custom_origins[i];
		}

		DrawTexturePro(textures[i], src, dest, origin, rotation, WHITE);
	}
}