cmake_minimum_required(VERSION 3.16)
project(ppvis)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

find_package(
  Qt5
  COMPONENTS Widgets
  REQUIRED)

file(GLOB_RECURSE SRC_LIST CONFIGURE_DEPENDS "src/*.h" "src/*.cpp" "ui/*.ui")

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
