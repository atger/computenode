cmake_minimum_required(VERSION 3.16)

project(App1)

add_subdirectory(libs/lib1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/libs/lib1/include/cursors.hpp")

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(app1
    main.cpp
	${HEADER_LIST}
)

target_link_libraries(app1 cursors)
target_include_directories(app1 PUBLIC "${PROJECT_SOURCE_DIR}/libs/lib1/include")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Packing)
