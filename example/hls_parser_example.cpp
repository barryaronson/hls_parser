#include <iostream>

#include "playlist.h"

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    return EXIT_FAILURE;
  }

  playlist pl(argv[1]);
  std::cout << pl.readLine() << std::endl;

  return EXIT_SUCCESS;
}