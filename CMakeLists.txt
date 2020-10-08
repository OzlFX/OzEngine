cmake_minimum_required(VERSION 3.10)
project(OzEngine)

#The Project Version Number
set (Oz_Engine_VERSION_MAJOR 1)
set (Oz_Engine_VERSION_MINOR 0)

include_directories(
	src
	Dependencies/glm
	Dependencies/imgui
	Dependencies/stb_image
	Dependencies/stb_vorbis
	Dependencies/msvc-windows-x86/glew/include
	Dependencies/msvc-windows-x86/GLFW/include
	Dependencies/msvc-windows-x86/AL/include
	Dependencies/spdlog/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/Dependencies/msvc-windows-x86/glew/lib/Release/x64
	${CMAKE_SOURCE_DIR}/Dependencies/msvc-windows-x86/GLFW/lib
	${CMAKE_SOURCE_DIR}/Dependencies/msvc-windows-x86/AL/lib
)

#Add the libraries to the project
add_library(OzEngine SHARED
	src/OzEngine/Core/Application.cpp
	src/OzEngine/Utilities/Log.cpp
	src/OzEngine/Utilities/Vector.h
	src/OzEngine/Core/EventHandler/EventHandler.h
	src/OzEngine/Core/Window/Window.h
	src/OzEngine/Core/Window/Window.cpp
	src/OzEngine/Core/Window/OpenGLWindow.h
	src/OzEngine/Core/Window/OpenGLWindow.cpp
)

target_compile_definitions(
	OzEngine
	PRIVATE -DBUILD_DLL
)

set_target_properties( OzEngine
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

target_link_libraries(OzEngine opengl32 OpenAL32 glew32)

#Add main executable
add_executable(Game
	src/Game/Program.cpp
)

target_link_libraries(Game OzEngine)