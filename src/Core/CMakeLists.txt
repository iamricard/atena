# Author: Ricard Sole
# Date: 30 March 2014

# GLOB all files in current directory
file(GLOB CORE_SRCS *.cpp *.h)

add_library(CORE ${CORE_SRCS})