#include "../include/allocator.h"
#include "raylib.h"
#include <stdlib.h>

void ArenaInit(Arena *arena, size_t capacity) {
  arena->data = malloc(capacity);
  arena->used = 0;
  arena->capacity = capacity;

  if (arena->data == NULL) {
    TraceLog(LOG_ERROR, "Could not init arena with size of %ldd", capacity);
  }
}

void *ArenaAlloc(Arena *arena, size_t size) {
  if ((arena->used + size) > arena->capacity) {
    TraceLog(LOG_ERROR,
             "Could not allocate chunk in arena. Requested %ldd for Arena with %ldd/%ldd", size,
             arena->used, arena->capacity);
  }

  void *head = arena->data;
  arena->data += size;
  arena->used += size;

  return head;
}

void ArenaFree(Arena *arena) {
  free(arena->data - arena->used);
  arena->data = NULL;
  arena->used = 0;
  arena->capacity = 0;
}
