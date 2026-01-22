#pragma once
#include "types.h"

#define TILE_SIZE 32

typedef struct {
  i32 width;
  i32 height;
} Overworld;

void DrawTiles(Overworld *overworld);
