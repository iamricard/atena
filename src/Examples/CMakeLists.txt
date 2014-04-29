# Author: Ricard Sole
# Date: 3 April 2014

# GLOB all files in current directory
file(GLOB SPRITE_SRCS *.cpp *.h)

add_library(SPRITE ${SPRITE_SRCS})