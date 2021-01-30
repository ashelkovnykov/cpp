cmake_minimum_required(VERSION 3.17.3)

add_library(ExpressionsLib SHARED)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")

list(APPEND SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND SOURCE_DIRS ${SRC_DIR})
list(APPEND SOURCE_DIRS ${HEADERS_DIR})

include_directories(${HEADERS_DIR})

target_include_directories(ExpressionsLib INTERFACE ${SOURCE_DIRS})
target_sources(ExpressionsLib PUBLIC "${SRC_DIR}/accessOperators.cpp" "${SRC_DIR}/arithmeticOperators.cpp" "${SRC_DIR}/assignmentOperators.cpp" "${SRC_DIR}/comparisonOperators.cpp" "${SRC_DIR}/dynamicMemory.cpp" "${SRC_DIR}/incrementOperators.cpp" "${SRC_DIR}/literals.cpp" "${SRC_DIR}/logicalOperators.cpp" "${SRC_DIR}/otherOperators.cpp")

install(TARGETS ExpressionsLib DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES expressionsLibrary.h "${HEADERS_DIR}/accessOperators.h" "${HEADERS_DIR}/arithmeticOperators.h" "${HEADERS_DIR}/assignmentOperators.h" "${HEADERS_DIR}/comparisonOperators.h" "${HEADERS_DIR}/dynamicMemory.h" "${HEADERS_DIR}/incrementOperators.h" "${HEADERS_DIR}/literals.h" "${HEADERS_DIR}/logicalOperators.h" "${HEADERS_DIR}/otherOperators.h" DESTINATION "${CMAKE_INSTALL_PREFIX}/include")