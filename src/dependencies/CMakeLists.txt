project(dependencies)

include_directories(${PROJECT_SOURCE_DIR}/include)

message("${PROJECT_SOURCE_DIR}/src/Project.cpp")

add_library(dependencies ${PROJECT_SOURCE_DIR}/src/Project.cpp)
