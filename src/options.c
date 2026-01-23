#include "../include/options.h"
#include <getopt.h>
#include <stdbool.h>

Options parseOptions(int argc, char **argv) {
  Options options = {0};

  int opt;
  while ((opt = getopt(argc, argv, "d")) != -1) {
    switch (opt) {
    case 'd':
      options.debugEnabled = true;
      break;
    }
  }

  return options;
}
