# Author: Ricard Sole
# Date: 3 April 2014

# GLOB all files in current directory
file(GLOB BAHAMUT_SRCS *.cpp *.h)

add_library(BAHAMUT ${BAHAMUT_SRCS})