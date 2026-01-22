#include "../include/overworld.h"
#include "../include/types.h"
#include "raylib.h"

void DrawTiles(Overworld *overworld) {
  for (u32 x = 0; x < overworld->width; ++x) {
    for (u32 y = 0; y < overworld->height; ++y) {
      DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED);
      DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
    }
  }
}
