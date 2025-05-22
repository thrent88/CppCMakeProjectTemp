set(BIN_NAME ${PROJECT_NAME})

file(GLOB_RECURSE SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

add_executable(${BIN_NAME} ${SOURCE})
target_link_libraries(${BIN_NAME} PUBLIC cpptrace::cpptrace)
target_include_directories(${BIN_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 为调出堆栈信息
if (MSVC)
  target_compile_options(${BIN_NAME} PRIVATE /Zi)
  target_link_options(${BIN_NAME} PRIVATE /DEBUG)
endif ()

if (WIN32)
  add_custom_command(
    TARGET ${BIN_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:cpptrace::cpptrace>
    $<TARGET_FILE_DIR:${BIN_NAME}>
  )
endif ()
