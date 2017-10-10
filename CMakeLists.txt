cmake_minimum_required(VERSION 3.8)
project(ProjectSFML)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/states/GameState.cpp src/states/GameState.h src/Game.cpp src/Game.h src/main.cpp)
add_executable(ProjectSFML ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ProjectSFML ${SFML_LIBRARIES})
endif()