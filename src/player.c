#include "../include/player.h"
#include "../include/sizes.h"
#include "raylib.h"

void DrawSprite(Player *player) {
  DrawRectangle(player->position.x * TILE_SIZE, player->position.y * TILE_SIZE, TILE_SIZE,
                TILE_SIZE, GREEN);
}
