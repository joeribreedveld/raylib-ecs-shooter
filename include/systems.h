#ifndef SYSTEMS_H
#define SYSTEMS_H

void render_system();

void movement_system(float dt, int screen_width, int screen_height);

void input_system(float speed);

#endif