#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [textures] example - logo raylib");
  SetTargetFPS(60);

  Texture2D texture = LoadTexture("resources/logo.png");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawTexture(texture, SCREEN_WIDTH / 2 - texture.width / 2,
                SCREEN_HEIGHT / 2 - texture.height / 2, WHITE);

    DrawText("this IS a texture!", 360, 370, 10, GRAY);

    EndDrawing();
  }

  UnloadTexture(texture);

  CloseWindow();

  return 0;
}
