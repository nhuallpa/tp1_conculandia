set(SOURCE
        ${SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/Util.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/SignalHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Menu.cpp
        PARENT_SCOPE
        )
set(HEADERS
        ${HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/Util.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SignalHandler.h
        ${CMAKE_CURRENT_SOURCE_DIR}/EventHandler.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SIGINT_Handler.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Menu.h
        PARENT_SCOPE
        )