#pragma once
#include "types.h"

typedef struct {
  bool debugEnabled;
} Options;

Options parseOptions(int argc, char **argv);
