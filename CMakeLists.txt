cmake_minimum_required(VERSION 3.15)

project(CppCMakeProjectTemp)

if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

if(MSVC)
  add_compile_options(/utf-8)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(${PROJECT_NAME}_BUILD_TESTS "Build tests" ON)

include(FetchContent)
FetchContent_Declare(
  cpptrace
  URL ${PROJECT_SOURCE_DIR}/3rd/cpptrace-0.8.3.zip
)
FetchContent_MakeAvailable(cpptrace)

include(CTest)

add_subdirectory(src/main)

if(${PROJECT_NAME}_BUILD_TESTS)
  add_subdirectory(src/test)
endif()

enable_testing()
