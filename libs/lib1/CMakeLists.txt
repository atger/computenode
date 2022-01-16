cmake_minimum_required(VERSION 3.16)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(HEADER_LIST "${CMAKE_CURRENT_SOURCE_DIR}/include/cursors.hpp")

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(cursors
	src/cursors.cpp
	${HEADER_LIST}
)

target_link_libraries(cursors Qt5::Widgets)
target_include_directories(cursors PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
