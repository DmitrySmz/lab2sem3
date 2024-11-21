# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\lab2sem3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\lab2sem3_autogen.dir\\ParseCache.txt"
  "lab2sem3_autogen"
  )
endif()
