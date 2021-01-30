cmake_minimum_required(VERSION 3.17.3)

add_library(TemplatesLib SHARED)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")

list(APPEND SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND SOURCE_DIRS ${SRC_DIR})
list(APPEND SOURCE_DIRS ${HEADERS_DIR})

include_directories(${HEADERS_DIR})

target_include_directories(TemplatesLib INTERFACE ${SOURCE_DIRS})
target_sources(TemplatesLib PUBLIC "${SRC_DIR}/classTemplates.cpp" "${SRC_DIR}/concepts.cpp" "${SRC_DIR}/functionTemplates.cpp")

install(TARGETS TemplatesLib DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES templatesLibrary.h "${HEADERS_DIR}/classTemplates.h" "${HEADERS_DIR}/concepts.h" "${HEADERS_DIR}/functionTemplates.h" "${HEADERS_DIR}/parameterPacks.h" "${HEADERS_DIR}/variableTemplates.h" DESTINATION "${CMAKE_INSTALL_PREFIX}/include")