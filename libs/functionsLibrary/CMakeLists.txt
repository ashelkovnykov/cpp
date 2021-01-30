cmake_minimum_required(VERSION 3.17.3)

add_library(FunctionsLib SHARED)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")

list(APPEND SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND SOURCE_DIRS ${SRC_DIR})
list(APPEND SOURCE_DIRS ${HEADERS_DIR})

include_directories(${HEADERS_DIR})

target_include_directories(FunctionsLib INTERFACE ${SOURCE_DIRS})
target_sources(FunctionsLib PUBLIC "${SRC_DIR}/fdeclarations.cpp" "${SRC_DIR}/lambda.cpp")

install(TARGETS FunctionsLib DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES functionsLibrary.h "${HEADERS_DIR}/fdeclarations.h" "${HEADERS_DIR}/lambda.h" DESTINATION "${CMAKE_INSTALL_PREFIX}/include")