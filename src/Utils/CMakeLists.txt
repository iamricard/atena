# Author: Ricard Sole
# Date: 30 March 2014

# GLOB all files in current directory
file(GLOB UTILS_SRCS *.cpp *.h)

add_library(UTILS ${UTILS_SRCS})
set_target_properties(UTILS PROPERTIES LINKER_LANGUAGE CXX)