set(CMAKE_RELEASE_DIR "../bin/release")
# debug binary folder
set(CMAKE_DEBUG_DIR "../bin/debug")


# find openCV
set(CMAKE_MODULE_PATH ${CMAKE_INSTALL_PREFIX}/lib/cmake/ )
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(AntTweakBar REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${GLFW_INCLUDE_DIRS})
add_executable (OpenGLib
  main.cpp
  GLApp.cpp
  SimpleGLApp.cpp
  VertexArray.cpp
  VertexBuffer.cpp
  ErrorFinder.cpp
  ShaderProgram.cpp
  Texture2D.cpp
  targa.cpp
  Terrain.cpp
  )

target_link_libraries (OpenGLib ${OPENGL_LIBRARY} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} ${ANT_TWEAK_BAR_LIBRARY})

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	set_target_properties(OpenGLib PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_DEBUG_DIR})
	set_target_properties(OpenGLib PROPERTIES OUTPUT_NAME OpenGLib${BUILD_PREFIX})
else()
	set_target_properties(OpenGLib PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RELEASE_DIR})
endif()
