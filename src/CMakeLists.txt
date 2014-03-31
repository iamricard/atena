# Author: Ricard Sole
# Date: 30 March 2014

# Add subdirectories
add_subdirectory(lib)
add_subdirectory(Game)

# GLOB all files in current directory
file(GLOB SRCS *.cpp *.h)

add_executable(Atena ${SRCS})
add_dependencies(Atena SDL2_image)
target_link_libraries(Atena core Box2D SDL2)