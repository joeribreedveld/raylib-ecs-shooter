#ifndef CAMERA_H
#define CAMERA_H

#include "raylib.h"

Camera2D camera_create(Vector2 position);

void camera_follow(Camera2D *camera, Vector2 target);

#endif