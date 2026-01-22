#include "../include/overworld.h"
#include "../include/player.h"
#include "../include/sizes.h"
#include "raylib.h"

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "arrpeegee");
  SetTraceLogLevel(LOG_DEBUG);
  SetTargetFPS(60);

  Overworld overworld = {.width = 300, .height = 200};
  Player player = {.position = {.x = 0, .y = 0}};
  Camera2D camera = {0};
  camera.offset = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
  camera.zoom = 1.0f;

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_RIGHT)) {
      player.position.x += 1;
    } else if (IsKeyDown(KEY_LEFT)) {
      player.position.x -= 1;
    } else if (IsKeyDown(KEY_UP)) {
      player.position.y -= 1;
    } else if (IsKeyDown(KEY_DOWN)) {
      player.position.y += 1;
    }

    camera.target = (Vector2){player.position.x * TILE_SIZE, player.position.y * TILE_SIZE};

    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode2D(camera);
    DrawTiles(&overworld, &player);
    DrawSprite(&player);
    EndMode2D();

    DrawFPS(20, 20);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
