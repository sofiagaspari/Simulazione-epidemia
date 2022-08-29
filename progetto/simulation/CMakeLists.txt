
add_executable(sir main.cpp)


add_library(window board.cpp epidemic.cpp)


set(LIBRARIES window)

target_link_libraries(sir ${LIBRARIES})

target_link_libraries("window" PUBLIC 
    "sfml-graphics" 
    "sfml-system"
    "sfml-window"
    
)
set(SFML_DIR "c:\\SFML\\lib\\cmake\\SFML\\")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED system REQUIRED)
target_link_libraries (sir sfml-graphics sfml-system sfml-window)

SET_TARGET_PROPERTIES(
        sir PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}"
)

