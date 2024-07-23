cmake_minimum_required(VERSION 3.21)
project(untitled22)

set(CMAKE_CXX_STANDARD 14)
add_executable(untitled22 main.cpp Player.cpp Player.h Platform.cpp Platform.h Bullet.cpp Bullet.h)



set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system windows graphics audio network REQUEIRED)

include_directories(C:/SFML/include)
target_link_libraries(untitled22 sfml-system sfml-window sfml-graphics sfml-audio)