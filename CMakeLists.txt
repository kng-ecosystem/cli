# CMake entry point
cmake_minimum_required (VERSION 3.5)
project (kng.cli)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# stops ZERO_BUILD from being generated
set(CMAKE_SUPPRESS_REGENERATION true)

include_directories(
	src/vendor/cxxopts/include
	src/vendor/Catch2-2.13.3/include
	src/vendor/spdlog-1.8.1/include
	src
)
set(ALL_FILES 
	./src/main.cpp 
	)

add_executable(Release ${ALL_FILES})