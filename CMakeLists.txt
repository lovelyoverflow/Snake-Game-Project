cmake_minimum_required(VERSION 3.0)
project(snake)

# Use our modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${snake_SOURCE_DIR}/cmake")
set(BIN_DIR ${snake_SOURCE_DIR})

# Bump up warning levels appropriately for clang, gcc & msvc and build in debug mode
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories("./src" "./include")
file (GLOB snake_SOURCES src/*.cpp)

add_executable(snake src/display.cpp src/snakemanager.cpp src/main.cpp src/point.cpp src/snake.cpp)
target_link_libraries(snake ${CURSES_LIBRARY})
install(TARGETS snake RUNTIME DESTINATION ${BIN_DIR})