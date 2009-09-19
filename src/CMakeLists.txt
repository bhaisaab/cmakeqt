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

