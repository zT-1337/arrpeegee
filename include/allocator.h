#pragma once
#include <stddef.h>

typedef struct {
  void *data;
  size_t used;
  size_t capacity;
} Arena;

void ArenaInit(Arena *arena, size_t capacity);
void *ArenaAlloc(Arena *arena, size_t size);
void ArenaFree(Arena *arena);
