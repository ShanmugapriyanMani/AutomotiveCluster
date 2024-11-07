# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AutomotiveCluster_autogen"
  "CMakeFiles/AutomotiveCluster_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/AutomotiveCluster_autogen.dir/ParseCache.txt"
  )
endif()
