cmake_minimum_required(VERSION 3.16)
project(lab2)

set(CMAKE_CXX_STANDARD 17)


include_directories(src)
include_directories(src/lib)

add_library(${CMAKE_PROJECT_NAME} SHARED src/napi.c src/lib/first_mode.h src/lib/first_mode.c)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api
    ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api/src
    ${CMAKE_JS_INC})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_LIB})