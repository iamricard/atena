# Author: Ricard Sole
# Date: 30 March 2014

# GLOB all files in current directory
file(GLOB SPRITE_SRCS *.cpp *.h)

add_library(sprite ${SPRITE_SRCS})