find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
   example.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}
   ${CMAKE_SOURCE_DIR}/lib/external
)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw)