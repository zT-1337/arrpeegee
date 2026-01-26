#include "../include/overworld.h"
#include "../include/math_util.h"
#include "../include/sizes.h"
#include "../include/types.h"
#include "raylib.h"
#include <stdio.h>

const i32 TILE_OFFSET_X = SCREEN_WIDTH / TILE_SIZE / 2 + 1;
const i32 TILE_OFFSET_Y = SCREEN_HEIGHT / TILE_SIZE / 2 + 1;

void DrawTiles(Overworld *overworld, Vector2 *center) {
  int renderedTiles = 0;
  i32 min_x = max(center->x - TILE_OFFSET_X, 0);
  i32 min_y = max(center->y - TILE_OFFSET_Y, 0);
  i32 max_x = min(center->x + TILE_OFFSET_X, overworld->width);
  i32 max_y = min(center->y + TILE_OFFSET_Y, overworld->height);

  Rectangle source = {0};
  source.width = TILE_SIZE;
  source.height = TILE_SIZE;

  for (i32 x = min_x; x < max_x; ++x) {
    for (i32 y = min_y; y < max_y; ++y) {
      for (i32 layerIdx = 0; layerIdx < LAYER_COUNT; ++layerIdx) {
        i32 tileIdx = overworld->tileLayers[layerIdx][overworld->width * y + x];
        TraceLog(LOG_DEBUG, "Render Tile Index %d", tileIdx);
        if (tileIdx == -1) {
          continue;
        }

        source.x = tileIdx * TILE_SIZE;
        Vector2 position = {.x = x * TILE_SIZE, .y = y * TILE_SIZE};
        DrawTextureRec(overworld->tileset, source, position, WHITE);
        ++renderedTiles;
      }
    }
  }

  TraceLog(LOG_DEBUG, "Rendered %d tiles", renderedTiles);
}

Overworld *LoadOverworld(Arena *arena, char *overworldFilePath) {
  Overworld *overworld = ArenaAlloc(arena, sizeof(Overworld));
  FILE *mapFile = fopen(overworldFilePath, "r");

  fscanf(mapFile, "%d %d\n", &overworld->width, &overworld->height);
  TraceLog(LOG_DEBUG, "Loading overworld with width %d and height %d", overworld->width,
           overworld->height);

  char tilesetPath[100];
  fscanf(mapFile, "%s\n", tilesetPath);
  overworld->tileset = LoadTexture(tilesetPath);
  TraceLog(LOG_DEBUG, "Loading Tileset %s for overworld", tilesetPath);

  LoadLayers(arena, overworld, mapFile);
  TraceLog(LOG_DEBUG, "Loaded all tile layers");

  fclose(mapFile);
  return overworld;
}

void LoadLayers(Arena *arena, Overworld *overworld, FILE *mapFile) {
  for (i32 layerIdx = 0; layerIdx < LAYER_COUNT; ++layerIdx) {
    overworld->tileLayers[layerIdx] =
        ArenaAlloc(arena, sizeof(i32) * overworld->width * overworld->height);
    for (i32 y = 0; y < overworld->height; ++y) {
      for (i32 x = 0; x < overworld->width; ++x) {
        i32 *tilePointer = overworld->tileLayers[layerIdx] + y * overworld->width + x;
        fscanf(mapFile, x < (overworld->width - 1) ? "%d " : "%d\n", tilePointer);
        TraceLog(LOG_DEBUG, "Loaded Tile %d at position x:%d y:%d -> %d", &tilePointer, x, y,
                 y * overworld->width + x);
      }
    }
  }
}

void UnloadOverworld(Overworld *overworld) { UnloadTexture(overworld->tileset); }
