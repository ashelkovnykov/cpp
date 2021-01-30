cmake_minimum_required(VERSION 3.17.3)

add_library(ConceptsLib SHARED)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")

list(APPEND SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND SOURCE_DIRS ${SRC_DIR})
list(APPEND SOURCE_DIRS ${HEADERS_DIR})

include_directories(${HEADERS_DIR})

# Note: Transactional memory doesn't seem to work
#SET(GCC_ADDITIONAL_FLAGS  "-fgnu-tm")
#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_ADDITIONAL_FLAGS}")

target_include_directories(ConceptsLib INTERFACE ${SOURCE_DIRS})
target_sources(ConceptsLib PUBLIC "${SRC_DIR}/exceptions.cpp" "${SRC_DIR}/namespaces.cpp" "${SRC_DIR}/statements.cpp")

install(TARGETS ConceptsLib DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES conceptsLibrary.h "${HEADERS_DIR}/comments.h" "${HEADERS_DIR}/declarations.h" "${HEADERS_DIR}/exceptions.h" "${HEADERS_DIR}/namespaces.h" "${HEADERS_DIR}/scope.h" "${HEADERS_DIR}/statements.h" "${HEADERS_DIR}/using.h" DESTINATION "${CMAKE_INSTALL_PREFIX}/include")