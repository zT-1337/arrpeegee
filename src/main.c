#include "../include/allocator.h"
#include "../include/options.h"
#include "../include/overworld.h"
#include "../include/player.h"
#include "../include/sizes.h"
#include "raylib.h"

int main(int argc, char **argv) {
  Options options = parseOptions(argc, argv);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "arrpeegee");
  SetTraceLogLevel(LOG_DEBUG);
  SetTargetFPS(60);

  Arena overworldArena = {0};
  ArenaInit(&overworldArena, 1000 * 1000);

  Overworld *overworld = LoadOverworld(&overworldArena, "resources/test.map");
  TraceLog(LOG_DEBUG, "%ld %ld", overworldArena.used, overworldArena.capacity);
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
    DrawTiles(overworld, &player.position);
    DrawSprite(&player);
    EndMode2D();

    if (options.debugEnabled) {
      DrawFPS(20, 20);
    }

    EndDrawing();
  }

  UnloadOverworld(overworld);
  ArenaFree(&overworldArena);

  CloseWindow();

  return 0;
}
