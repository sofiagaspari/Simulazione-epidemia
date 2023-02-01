cmake_minimum_required(VERSION 3.16)
project(sir VERSION 0.1.0)

include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address -fno-omit-frame-pointer")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(sir ./simulation/main.cpp ./simulation/epidemic.cpp ./simulation/board.cpp)

target_link_libraries(sir PRIVATE sfml-graphics sfml-system sfml-window)

if (BUILD_TESTING)

  add_executable(sir-test ./tests/test.cpp ./simulation/epidemic.cpp)
  target_link_libraries(sir-test PRIVATE sfml-graphics)
  add_test(NAME sir-test COMMAND sir-test)

endif()
