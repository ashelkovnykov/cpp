cmake_minimum_required(VERSION 3.17.3)

add_library(SpecifiersLib SHARED)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")

list(APPEND SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND SOURCE_DIRS ${SRC_DIR})
list(APPEND SOURCE_DIRS ${HEADERS_DIR})

include_directories(${HEADERS_DIR})

target_include_directories(SpecifiersLib INTERFACE ${SOURCE_DIRS})
target_sources(SpecifiersLib PUBLIC "${SRC_DIR}/attributes.cpp" "${SRC_DIR}/specifiers.cpp")

install(TARGETS SpecifiersLib DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES specifiersLibrary.h "${HEADERS_DIR}/attributes.h" "${HEADERS_DIR}/specifiers.h" DESTINATION "${CMAKE_INSTALL_PREFIX}/include")