#ifndef MAP_H
#define MAP_H

#define TILE_SIZE 64
#define MAX_TILES 2048

void map_load(const char *map_file, const char *tileset_file);
void map_draw(void);

#endif
