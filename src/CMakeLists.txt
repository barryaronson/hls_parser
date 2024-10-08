# CMakeLists.txt for creating a library

cmake_minimum_required(VERSION 3.10)
project(hls_parser)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the source files for the library
add_library(hls_parser playlist.cpp ${CMAKE_SOURCE_DIR}/include/hls_parser/playlist.h)

# Specify include directories for the library (if needed)
target_include_directories(hls_parser PUBLIC ${CMAKE_SOURCE_DIR}/include/hls_parser)

# Specify installation location for the library
install(TARGETS hls_parser DESTINATION lib)
install(FILES hls_parser.h DESTINATION include/hls_parser)