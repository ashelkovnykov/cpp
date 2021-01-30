cmake_minimum_required(VERSION 3.17.3)

file(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/dummy.cpp" "")
add_library(ClassLib SHARED "${CMAKE_CURRENT_SOURCE_DIR}/dummy.cpp")

set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")

list(APPEND SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND SOURCE_DIRS ${HEADERS_DIR})

target_include_directories(ClassLib INTERFACE ${SOURCE_DIRS})

install(TARGETS ClassLib DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES classesLibrary.h "${HEADERS_DIR}/class.h" DESTINATION "${CMAKE_INSTALL_PREFIX}/include")