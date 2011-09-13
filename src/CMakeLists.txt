#
# CMakeQt: CMake build system template for Qt based projects
# Author: Rohit Yadav <rohityadav89 AT gmail.com>
#

#Put here CPPs
SET(CMAKEQT_SRCS
    main.cpp
)

SET(CMAKEQT_HDRS
)

#Put here QRC files to be Rcc-ed
SET(CMAKEQT_RCC
    resources.qrc
    ../ts/resources-ts.qrc
)

#include paths for vlmc
INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/src
  .
)

CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/cmake/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

LIST( APPEND CMAKEQT_SRCS
             CMakeQt.cpp )

LIST( APPEND CMAKEQT_HDRS
             CMakeQt.h )

#Put here UI files
SET(CMAKEQT_UIS
        CMakeQt.ui
)

QT4_WRAP_UI(CMAKEQT_UIS_H ${CMAKEQT_UIS})
QT4_ADD_RESOURCES(CMAKEQT_RCC_SRCS ${CMAKEQT_RCC})
QT4_WRAP_CPP(CMAKEQT_MOC_SRCS ${CMAKEQT_HDRS})

IF( MINGW )
    # resource compilation for MinGW
    ADD_CUSTOM_COMMAND( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/icon.o
        COMMAND ${CMAKE_WINDRES} -I${CMAKE_SOURCE_DIR} -i${CMAKE_SOURCE_DIR}/cmake/icon.rc
        -o ${CMAKE_CURRENT_BINARY_DIR}/icon.o )
    SET(CMAKEQT_SRCS ${CMAKEQT_SRCS} ${CMAKE_CURRENT_BINARY_DIR}/icon.o)
    SET(LINK_FLAGS -Wl,-subsystem,windows)
ENDIF( MINGW )

IF(WIN32)
    SET(GUI_TYPE WIN32)
ENDIF(WIN32)

IF(APPLE)
    SET(GUI_TYPE MACOSX_BUNDLE)
    SET(CMAKEQT_SRCS ${CMAKEQT_SRCS} ../share/cmakeqt.icns)
    SET_SOURCE_FILES_PROPERTIES(../share/cmakeqt.icns PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources)
    SET(MACOSX_BUNDLE_ICON_FILE cmakeqt.icns)
ENDIF(APPLE)

ADD_EXECUTABLE(cmakeqt ${CMAKEQT_SRCS} ${CMAKEQT_MOC_SRCS} ${CMAKEQT_UIS_H} ${CMAKEQT_RCC_SRCS} )

# Add translations
ADD_DEPENDENCIES(cmakeqt translations)

# Link the target against the Qt libraries
TARGET_LINK_LIBRARIES(cmakeqt ${CMAKEQT_LIBS})

# Now we are done.

INSTALL(TARGETS cmakeqt
        BUNDLE  DESTINATION ${CMAKEQT_BIN_DIR}
        RUNTIME DESTINATION ${CMAKEQT_BIN_DIR})

ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_SOURCE_DIR}/bin/cmakeqt
    COMMAND ${CMAKE_COMMAND} copy ${CMAKE_CURRENT_SOURCE_DIR}/cmakeqt ${CMAKE_SOURCE_DIR}/bin/cmakeqt
    DEPENDS ${CMAKE_BINARY_DIR}/src/cmakeqt
)

ADD_DEFINITIONS(-W -Wall)

# Creates app bundle in /bin, uncomment #-dmg to create a dmg output 
IF( APPLE )
    ADD_CUSTOM_COMMAND(
        TARGET cmakeqt
        POST_BUILD
        COMMAND macdeployqt ${CMAKE_CURRENT_BINARY_DIR}/../bin/cmakeqt.app -no-plugins #-dmg
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Deploying the Qt Framework onto the bundle"
    )
ENDIF( APPLE )

