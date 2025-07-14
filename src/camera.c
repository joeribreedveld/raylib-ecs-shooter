#include "camera.h"

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
	camera->target.x = (int)target.x;
	camera->target.y = (int)target.y;
}
