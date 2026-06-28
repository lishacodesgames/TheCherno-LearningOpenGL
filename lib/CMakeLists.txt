if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/external/GLFW/CMakeLists.txt)
   message(NOTICE "!! GLFW submodule is empty !!")
   message(STATUS "Updating submodule now...\n")
   
   find_package(Git REQUIRED)
   execute_process(
      COMMAND ${GIT_EXECUTABLE} submodule update --init --depth 1
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
      COMMAND_ECHO STDOUT
      RESULT_VARIABLE GIT_RESULT
   )

   if(NOT GIT_RESULT EQUAL 0)
      message(FATAL_ERROR "Failed to update git submodule!")
   else()
      message(NOTICE "Submodule successfully updated!\n")
   endif()
endif()

set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(external/GLFW)
