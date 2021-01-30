cmake_minimum_required(VERSION 3.17.3)

project(MyCPP VERSION 1.0.0 DESCRIPTION "C++ language and best practices reference" LANGUAGES CXX)

SET(GCC_ADDITIONAL_FLAGS  "-std=c++2a -fpermissive")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_ADDITIONAL_FLAGS}")

add_executable(mainExecutable ./src/main.cpp)

add_subdirectory(./libs/classesLibrary)
add_subdirectory(./libs/conceptsLibrary)
add_subdirectory(./libs/expressionsLibrary)
add_subdirectory(./libs/functionsLibrary)
add_subdirectory(./libs/preprocessorLibrary)
add_subdirectory(./libs/specifiersLibrary)
add_subdirectory(./libs/templatesLibrary)
add_subdirectory(./libs/typesLibrary)

list(APPEND ADD_LIBS ClassLib)
list(APPEND ADD_LIBS ConceptsLib)
list(APPEND ADD_LIBS ExpressionsLib)
list(APPEND ADD_LIBS FunctionsLib)
list(APPEND ADD_LIBS PreprocessorLib)
list(APPEND ADD_LIBS SpecifiersLib)
list(APPEND ADD_LIBS TemplatesLib)
list(APPEND ADD_LIBS TypesLib)

target_link_libraries(mainExecutable PUBLIC ${ADD_LIBS})

install(TARGETS mainExecutable DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

add_custom_command(TARGET mainExecutable
        POST_BUILD
        COMMAND echo "Compiled ${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_VERSION}"
        USES_TERMINAL)