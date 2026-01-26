#pragma once
#include "raylib.h"

typedef struct {
  Vector2 position;
} Player;

void DrawSprite(Player *player);
