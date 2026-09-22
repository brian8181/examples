
# @name     pipewire1
# @file:    CMakeLists.txt
# @date:    Tue, 22 Sep 2026 06:38:52 +0000
# @version: 0.0.1

cmake_minimum_required(VERSION 3.28.3)
project(scanner)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(BUILD_SHARED_LIBS YES)

if(CMAKE_SYSTEM_NAME STREQUAL "CYGWIN")
    message(STATUS "Building under Cygwin, defining CYGWIN macro")
    add_definitions(-DCYGWIN)
endif()

add_executable(pipewire1
    src/pipewire1.cpp
    src/main.cpp
)


add_library(pipewire1_a STATIC
    src/pipewire1.cpp

)

#[=[
    # Add Library
    add_library(targetName [STATIC | SHARED | MODULE]
    [EXCLUDE_FROM_ALL]
    source1 [source2 ...]
)
]=]`

#[=[
install(TARGETS MyApp AlgoRuntime AlgoSDK
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
]=]
