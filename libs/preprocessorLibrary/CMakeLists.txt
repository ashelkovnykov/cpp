cmake_minimum_required(VERSION 3.17.3)

add_library(PreprocessorLib SHARED)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")

list(APPEND SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND SOURCE_DIRS ${SRC_DIR})
list(APPEND SOURCE_DIRS ${HEADERS_DIR})

include_directories(${HEADERS_DIR})

target_include_directories(PreprocessorLib INTERFACE ${SOURCE_DIRS})
target_sources(PreprocessorLib PUBLIC "${SRC_DIR}/control.cpp" "${SRC_DIR}/inclusion.cpp" "${SRC_DIR}/replacement.cpp")

install(TARGETS PreprocessorLib DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES preprocessorLibrary.h "${HEADERS_DIR}/control.h" "${HEADERS_DIR}/inclusion.h" "${HEADERS_DIR}/replacement.h" DESTINATION "${CMAKE_INSTALL_PREFIX}/include")