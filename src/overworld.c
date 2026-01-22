#include "../include/overworld.h"
#include "../include/sizes.h"
#include "../include/types.h"
#include "raylib.h"

void DrawTiles(Overworld *overworld, Camera2D *camera) {
  int renderedTiles = 0;
  Vector2 center = {.x = camera->target.x + camera->offset.x,
                    .y = camera->target.y + camera->offset.y};
  for (u32 x = 0; x < overworld->width; ++x) {
    for (u32 y = 0; y < overworld->height; ++y) {
      DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED);
      ++renderedTiles;
    }
  }

  TraceLog(LOG_DEBUG, "Camera Center {x: %f, y: %f} tiles", center.x, center.y);
  TraceLog(LOG_DEBUG, "Rendered %d tiles", renderedTiles);
}
