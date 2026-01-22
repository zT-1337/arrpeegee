#pragma once
#include "player.h"
#include "types.h"
#include <raylib.h>

typedef struct {
  i32 width;
  i32 height;
} Overworld;

void DrawTiles(Overworld *overworld, Player *player);
