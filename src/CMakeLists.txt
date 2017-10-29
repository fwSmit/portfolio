cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project (portfolio)

set (CMAKE_CXX_STANDARD 11)

file(GLOB portfolio_SRC
    "${CMAKE_SOURCE_DIR}/src/dependencies/src/*"
)

add_subdirectory(dependencies)
add_subdirectory(projects/lightrays)
add_subdirectory(projects/image_drawing)

include_directories("${CMAKE_SOURCE_DIR}/projects/lightrays/include")
include_directories("${CMAKE_SOURCE_DIR}/projects/image_drawing")
include_directories("${CMAKE_SOURCE_DIR}/projects/image_drawing/images")
include_directories(${CMAKE_SOURCE_DIR}/dependencies/include)

#include the necessary libraries
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package(TGUI 0.7 REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "Could not find SFML")
endif()

if(NOT TGUI_FOUND)
    message(FATAL_ERROR "Could not find TGUI")
endif()

add_executable(portfolio main.cpp ${portfolio_SRC})
target_link_libraries(portfolio ${TGUI_LIBRARY} ${SFML_LIBRARIES} dependencies lightrays_lib image_drawing)
