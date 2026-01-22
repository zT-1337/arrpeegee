#include "../include/overworld.h"
#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "arrpeegee");
  SetTargetFPS(60);

  Overworld overworld = {.width = 300, .height = 200};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTiles(&overworld);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
