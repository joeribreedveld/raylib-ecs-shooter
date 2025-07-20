#include "raylib.h"
#include "cjson/cJSON.h"

#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 16
#define MAP_HEIGHT 16
#define TILE_SIZE 64
#define MAX_TILES (MAP_WIDTH * MAP_HEIGHT)

struct tile {
	int id;
	int x;
	int y;
};

struct tile tiles[MAX_TILES];

int tile_count = 0;

Texture2D tileset;

void map_load(const char *map_file, const char *tileset_file)
{
	FILE *f = fopen(map_file, "rb");

	if (!f) {
		return;
	}

	fseek(f, 0, SEEK_END);

	long len = ftell(f);

	fseek(f, 0, SEEK_SET);

	char *data = malloc(len + 1);

	fread(data, 1, len, f);
	fclose(f);

	data[len] = '\0';

	cJSON *root = cJSON_Parse(data);

	free(data);

	if (!root) {
		return;
	}

	tileset = LoadTexture(tileset_file);

	cJSON *layers = cJSON_GetObjectItem(root, "layers");
	cJSON *layer0 = cJSON_GetArrayItem(layers, 0);
	cJSON *tile_array = cJSON_GetObjectItem(layer0, "tiles");

	int count = cJSON_GetArraySize(tile_array);

	for (int i = 0; i < count; i++) {
		cJSON *tile = cJSON_GetArrayItem(tile_array, i);

		tiles[tile_count].id =
			atoi(cJSON_GetObjectItem(tile, "id")->valuestring);

		tiles[tile_count].x = cJSON_GetObjectItem(tile, "x")->valueint;
		tiles[tile_count].y = cJSON_GetObjectItem(tile, "y")->valueint;

		tile_count++;
	}

	cJSON_Delete(root);
}

void map_draw()
{
	int cols = tileset.width / TILE_SIZE;

	for (int i = 0; i < tile_count; i++) {
		int id = tiles[i].id;
		int tx = id % cols;
		int ty = id / cols;

		Rectangle src = { tx * TILE_SIZE, ty * TILE_SIZE, TILE_SIZE,
				  TILE_SIZE };

		Vector2 pos = { tiles[i].x * TILE_SIZE,
				tiles[i].y * TILE_SIZE };

		DrawTextureRec(tileset, src, pos, WHITE);
	}
}
