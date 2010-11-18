#
# Toolchain to enable cross-compilation for Windows on Linux
# Authors: Rohit Yadav <rohityadav89@gmail.com>
#

SET(CMAKE_SYSTEM_NAME Windows)
SET(CMAKE_SYSTEM_VERSION 7)

# specify the cross compiler
IF(NOT CMAKE_C_COMPILER)
SET(CMAKE_C_COMPILER   i586-mingw32msvc-gcc)
ENDIF(NOT CMAKE_C_COMPILER)
IF(NOT CMAKE_CXX_COMPILER)
SET(CMAKE_CXX_COMPILER i586-mingw32msvc-g++)
ENDIF(NOT CMAKE_CXX_COMPILER)
IF(NOT CMAKE_WINDRES)
SET(CMAKE_WINDRES      i586-mingw32msvc-windres)
ENDIF(NOT CMAKE_WINDRES)

# where is the target environment 
SET(CMAKE_FIND_ROOT_PATH  ${CMAKE_SOURCE_DIR}/contribs)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ALWAYS)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ALWAYS)
SET(CMAKE_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/contribs/include)
