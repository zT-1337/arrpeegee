#include "../include/overworld.h"
#include "../include/math_util.h"
#include "../include/sizes.h"
#include "../include/types.h"
#include "raylib.h"

const i32 TILE_OFFSET_X = SCREEN_WIDTH / TILE_SIZE / 2 + 1;
const i32 TILE_OFFSET_Y = SCREEN_HEIGHT / TILE_SIZE / 2 + 1;

void DrawTiles(Overworld *overworld, Player *player) {
  int renderedTiles = 0;
  i32 min_x = max(player->position.x - TILE_OFFSET_X, 0);
  i32 min_y = max(player->position.y - TILE_OFFSET_Y, 0);
  i32 max_x = min(player->position.x + TILE_OFFSET_X, overworld->width);
  i32 max_y = min(player->position.y + TILE_OFFSET_Y, overworld->height);

  for (i32 x = min_x; x < max_x; ++x) {
    for (i32 y = min_y; y < max_y; ++y) {
      DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED);
      ++renderedTiles;
    }
  }

  TraceLog(LOG_DEBUG, "Rendered %d tiles", renderedTiles);
}
