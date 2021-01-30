cmake_minimum_required(VERSION 3.17.3)

file(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/dummy.cpp" "")
add_library(TypesLib SHARED "${CMAKE_CURRENT_SOURCE_DIR}/dummy.cpp")

set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")

list(APPEND SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND SOURCE_DIRS ${HEADERS_DIR})

target_include_directories(TypesLib INTERFACE ${SOURCE_DIRS})

install(TARGETS TypesLib DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES typesLibrary.h "${HEADERS_DIR}/arrays.h" "${HEADERS_DIR}/enumerations.h" "${HEADERS_DIR}/functions.h" "${HEADERS_DIR}/fundamental.h" "${HEADERS_DIR}/pointers.h" "${HEADERS_DIR}/qualifiers.h" "${HEADERS_DIR}/references.h" "${HEADERS_DIR}/types.h" "${HEADERS_DIR}/unions.h" DESTINATION "${CMAKE_INSTALL_PREFIX}/include")