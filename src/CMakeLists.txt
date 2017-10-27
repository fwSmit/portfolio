cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project (portfolio)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(projects/lightrays)
#include_directories(projects/lightrays/include)
#add_external(lightrays)

#add_dependencies(portfolio lightrays)

include_directories("${CMAKE_SOURCE_DIR}/projects/lightrays/include")

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

add_executable(portfolio main.cpp)
target_link_libraries(portfolio ${TGUI_LIBRARY} ${SFML_LIBRARIES} lightrays_lib)
