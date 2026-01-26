#pragma once
#include "allocator.h"
#include "player.h"
#include "raylib.h"
#include "types.h"
#include <stdio.h>

#define LAYER_COUNT 2

typedef struct {
  i32 width;
  i32 height;
  Texture tileset;
  i32 *tileLayers[LAYER_COUNT];
} Overworld;

void DrawTiles(Overworld *overworld, Vector2 *center);
Overworld *LoadOverworld(Arena *arena, char *overworldFilePath);
void LoadLayers(Arena *arena, Overworld *overworld, FILE *mapFile);
void UnloadOverworld(Overworld *overworld);
