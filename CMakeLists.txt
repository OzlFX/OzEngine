cmake_minimum_required(VERSION 3.19)
project(OzEngine)

#The Project Version Number
SET(Oz_Engine_VERSION_MAJOR 1)
SET(Oz_Engine_VERSION_MINOR 0)

include_directories(
	src
	Dependencies/glm
	Dependencies/imgui
	Dependencies/stb_image
	Dependencies/stb_vorbis
	Dependencies/msvc-windows-x86/glew/include
	Dependencies/msvc-windows-x86/glfw-3.3.4.bin.WIN32/include
	Dependencies/msvc-windows-x86/AL/include
	Dependencies/spdlog/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/Dependencies/msvc-windows-x86/glew/lib/Release/Win32
	${CMAKE_SOURCE_DIR}/Dependencies/msvc-windows-x86/glfw-3.3.4.bin.WIN32/lib-vc2019
	${CMAKE_SOURCE_DIR}/Dependencies/msvc-windows-x86/AL/lib
)

#Add the libraries to the project
add_library(OzEngine SHARED
	src/OzEngine/Core/Core.h
	src/OzEngine/Core/Base.h
	src/OzEngine/Core/EntryPoint.h
	src/OzEngine/Core/Application.h
	src/OzEngine/Core/Application.cpp
	src/OzEngine/Core/OzEngine.h
	src/OzEngine/Core/PlatformDetection.h
	src/OzEngine/Core/EventHandler/EventHandler.h
	src/OzEngine/Core/Window/Window.h
	src/OzEngine/Core/Window/Window.cpp
	src/OzEngine/Core/Window/OpenGLWindow.h
	src/OzEngine/Core/Window/OpenGLWindow.cpp
	src/OzEngine/Utilities/Log.cpp
	src/OzEngine/Utilities/Vector.h
	src/OzEngine/RenderSystem/GraphicsContext.h
	src/OzEngine/RenderSystem/GraphicsContext.cpp
	src/OzEngine/RenderSystem/OpenGL/OpenGLContext.h
	src/OzEngine/RenderSystem/OpenGL/OpenGLContext.cpp
)

#set(CMAKE_CXX_FLAGS_RELEASE "/MT")
#set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

#set_property(TARGET OzEngine PROPERTY
#	MSVC_RUNTIME_LIBRARY "MultiThreaded"
#)

set_target_properties( OzEngine
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

target_link_libraries(OzEngine OpenAL32 glfw3 glew32)

target_compile_definitions(
	OzEngine
	PRIVATE -DBUILD_DLL
)

#Add main executable
add_executable(Game
	src/Game/Program.cpp
)

target_link_libraries(Game OzEngine)

set_target_properties( Game
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)