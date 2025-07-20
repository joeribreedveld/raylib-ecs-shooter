#include "camera.h"
#include "raymath.h"

#include <stdlib.h>

Camera2D camera_create(Vector2 position)
{
	return (Camera2D){ .zoom = 1.0f,
			   .offset = { GetScreenWidth() / 2.0f,
				       GetScreenHeight() / 2.0f },
			   .target = position };
}

void camera_follow(Camera2D *camera, Vector2 target)
{
	camera->target.x = (int)roundf(target.x);
	camera->target.y = (int)roundf(target.y);

	Vector2 min = { 320, 240 };
	Vector2 max = { 704, 784 };

	camera->target = Vector2Clamp(camera->target, min, max);
}
