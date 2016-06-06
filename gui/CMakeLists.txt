cmake_minimum_required(VERSION 3.3 )
project(ColorIt)

set(SOURCE_FILES  ${SOURCE_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ui_mainwindow.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/RasterLabel.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/RasterLabel.cpp
        PARENT_SCOPE)
