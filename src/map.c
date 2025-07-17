#include "raylib.h"
#include "cjson/cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

int tile_ids[MAX_TILES];
int tile_xs[MAX_TILES];
int tile_ys[MAX_TILES];
int tile_layers[MAX_TILES];
char layer_names[16][16];
int tile_count = 0;
int layer_count = 0;

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

	layer_count = cJSON_GetArraySize(layers);

	for (int layer_idx = 0; layer_idx < layer_count; layer_idx++) {
		cJSON *layer = cJSON_GetArrayItem(layers, layer_idx);

		const char *name =
			cJSON_GetObjectItem(layer, "name")->valuestring;

		strncpy(layer_names[layer_idx], name, 15);

		layer_names[layer_idx][15] = '\0';

		cJSON *tiles = cJSON_GetObjectItem(layer, "tiles");

		int count = cJSON_GetArraySize(tiles);

		for (int i = 0; i < count; i++) {
			cJSON *tile = cJSON_GetArrayItem(tiles, i);

			int id = (int)strtol(
				cJSON_GetObjectItem(tile, "id")->valuestring,
				NULL, 10);

			int x = cJSON_GetObjectItem(tile, "x")->valueint;
			int y = cJSON_GetObjectItem(tile, "y")->valueint;

			tile_ids[tile_count] = id;
			tile_xs[tile_count] = x;
			tile_ys[tile_count] = y;
			tile_layers[tile_count] = layer_idx;
			tile_count++;
		}
	}

	cJSON_Delete(root);
}

void map_draw()
{
	int cols = tileset.width / TILE_SIZE;

	const char *draw_order[] = { "GRASS", "FLOORS", "WALLS" };

	for (int d = 0; d < 3; d++) {
		for (int l = 0; l < layer_count; l++) {
			if (strcmp(layer_names[l], draw_order[d]) != 0) {
				continue;
			}

			for (int i = 0; i < tile_count; i++) {
				if (tile_layers[i] != l) {
					continue;
				}

				int id = tile_ids[i];
				int tx = id % cols;
				int ty = id / cols;

				Rectangle src = { tx * TILE_SIZE,
						  ty * TILE_SIZE, TILE_SIZE,
						  TILE_SIZE };

				Vector2 pos = { tile_xs[i] * TILE_SIZE,
						tile_ys[i] * TILE_SIZE };

				DrawTextureRec(tileset, src, pos, WHITE);
			}
		}
	}
}
