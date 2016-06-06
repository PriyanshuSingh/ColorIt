cmake_minimum_required(VERSION 3.3 )
project(ColorIt)

set(SOURCE_FILES  ${SOURCE_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/BlendPixel.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ColorBlender.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ColorBlender.cpp
        PARENT_SCOPE)