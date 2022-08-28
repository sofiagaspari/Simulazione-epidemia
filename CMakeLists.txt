CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
project(sir)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(${PROJECT_NAME} main.cpp)


add_library(window board.cpp epidemic.hpp epidemic.cpp )


set(LIBRARIES window)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

target_link_libraries("window" PUBLIC 
    "sfml-graphics" 
    
)
set(SFML_DIR "c:\\SFML\\lib\\cmake\\SFML\\")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics)
