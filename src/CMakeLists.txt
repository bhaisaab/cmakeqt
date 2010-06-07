#
# CMakeQt
# CMake build system framework for Qt based projects
#
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
)

#include paths for vlmc
INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/src
  .
)

CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/cmake/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

LIST( APPEND CMAKEQT_SRCS
             AutoQt.cpp )

LIST( APPEND CMAKEQT_HDRS
             AutoQt.h )

#Put here UI files
SET(CMAKEQT_UIS
        AutoQt.ui
)

#Put here .TS files (if any)
#SET(TRANs
#)

QT4_WRAP_UI(CMAKEQT_UIS_H ${CMAKEQT_UIS})
QT4_ADD_RESOURCES(CMAKEQT_RCC_SRCS ${CMAKEQT_RCC})
QT4_WRAP_CPP(CMAKEQT_MOC_SRCS ${CMAKEQT_HDRS})

#QT4_ADD_TRANSLATION(TRANS_H ${TRANs})

ADD_EXECUTABLE(cmakeqt ${CMAKEQT_SRCS} ${CMAKEQT_MOC_SRCS} ${CMAKEQT_UIS_H} ${CMAKEQT_RCC_SRCS} )

#Link the target against the Qt libraries
TARGET_LINK_LIBRARIES(
    cmakeqt
    ${QT_QTCORE_LIBRARY} 
    ${QT_QTGUI_LIBRARY} 
    ${QT_QTXML_LIBRARY} 
    ${QT_QTSVG_LIBRARY})

#Now we are done. Easy with CMake!!!

# --- Install
INSTALL(TARGETS cmakeqt
        BUNDLE  DESTINATION ${CMAKEQT_BIN_DIR}
        RUNTIME DESTINATION ${CMAKEQT_BIN_DIR})

ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_SOURCE_DIR}/bin/cmakeqt
    COMMAND ${CMAKE_COMMAND} copy ${CMAKE_CURRENT_SOURCE_DIR}/cmakeqt ${CMAKE_SOURCE_DIR}/bin/cmakeqt
    DEPENDS ${CMAKE_BINARY_DIR}/src/cmakeqt
)

ADD_DEFINITIONS(-W -Wall)

