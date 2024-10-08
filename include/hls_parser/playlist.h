#pragma once

#include <fstream>

class playlist : public std::ifstream {
public:
  playlist(const char *fileName, size_t initialBufferSize = 512);
  ~playlist();
  std::string readLine();

private:
  size_t readBufferSize;
  char *readBuffer;
  std::ifstream hlsFile;
};