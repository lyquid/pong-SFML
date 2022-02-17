cmake_minimum_required(VERSION 3.11...3.20)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(
  Pong-SFML
  VERSION 0.1.0
  DESCRIPTION "Pong clone"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(DEFINED CMAKE_TOOLCHAIN_FILE)
	message(STATUS "Using vcpkg toolchain file.")
	find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
else()
	message(STATUS "No vcpkg toolchain file found!")
endif()

add_subdirectory(lib)
add_subdirectory(src)
