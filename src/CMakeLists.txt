set(CMAKE_RELEASE_DIR "../bin/release")
# debug binary folder
set(CMAKE_DEBUG_DIR "../bin/debug")


# find openCV
set(CMAKE_MODULE_PATH ${CMAKE_INSTALL_PREFIX}/lib/cmake/ )
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR} ${GLFW_INCLUDE_DIRS})
add_executable (OpenGLib
  main.cpp
  )

target_link_libraries (OpenGLib ${OPENGL_LIBRARY})

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	set_target_properties(OpenGLib PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_DEBUG_DIR})
	set_target_properties(OpenGLib PROPERTIES OUTPUT_NAME OpenGLib${BUILD_PREFIX})
else()
	set_target_properties(OpenGLib PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RELEASE_DIR})
endif()
