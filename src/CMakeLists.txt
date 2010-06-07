#CMakeQt by Rohit Yadav<rohityadav89@gmail.com>
#CMake Build System for Qt

include(${QT_USE_FILE})

#Put here CPPs
SET(CPPs
    main.cpp
    autoqt.cpp
)

#Put here UI files
SET(UIs
    interface.ui
)

#Put here H/HPPs to be Moc-ed
SET(MOCs
    autoqt.h
)

#Put here QRC files to be Rcc-ed
SET(RCCs 
    resources.qrc
)

#Put here .TS files (if any)
SET(TRANs
)

# generate rules for building source files from the resources
QT4_ADD_RESOURCES(RCCs_CPP ${RCCs})
QT4_WRAP_UI(UIs_H ${UIs})
QT4_WRAP_CPP(MOC_CPPs ${MOCs})
QT4_ADD_TRANSLATION(TRANS_H ${TRANs})

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(cmakeqt ${CPPs} ${MOC_CPPs} ${UIs_H} ${RCCs_CPP} )

#Link the target against the Qt libraries
target_link_libraries(cmakeqt ${QT_LIBRARIES})

#Now we are done. Easy with CMake!!!

# --- Install
install ( TARGETS cmakeqt
          DESTINATION ${CMAKE_INSTALL_PREFIX}/lib )

install ( TARGETS cmakeqt
          DESTINATION ${CMAKE_INSTALL_PREFIX}/bin )

file ( GLOB_RECURSE hpp_files . *.h *.hpp)
install ( FILES ${hpp_files}
          DESTINATION ${CMAKE_INSTALL_PREFIX}/include )

#install ( FILES ${PROJECT_BINARY_DIR}/hugr.pc
#         DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig )


# --- Package generation
set ( PACKAGE_NAME ${PROJECT_NAME} )
set ( PACKAGE_VERSION "0.0.1" )
set ( PACKAGE_RELEASE 0 )
set ( PACKAGE_MAINTAINER_NAME "Rohit Yadav" )
set ( PACKAGE_MAINTAINER_EMAIL "rohityadav89@gmail.com" )
set ( PACKAGE_DESCRIPTION "CMake Build System for Qt" )
set ( PACKAGE_DESCRIPTION_SUMMARY "CMakeQt" )
set ( PACKAGE_DEPENDS ${hugr_dependencies} )

# Debian packages
include ( ../CMake/DpkgDeb.cmake )
if ( DPKG_FOUND )
    add_debian_package ( ${PROJECT_NAME} )
endif ( DPKG_FOUND )

# RPM packages
#include ( ../CMake/Rpmbuild.cmake )
#set ( PACKAGE_GROUP "Groupe" )
#set ( PACKAGE_LICENSE "LGPL" )

#if ( RPMBUILD_FOUND )
#    add_rpm ( ${PROJECT_NAME} )
#endif ( RPMBUILD_FOUND )


