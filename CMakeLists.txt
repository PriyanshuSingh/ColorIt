cmake_minimum_required(VERSION 3.3 )
project(ColorIt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_PREFIX_PATH /Users/tgz/Documents/Devlopment/Qt/5.5/clang_64)

###################
#set automoc for qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(SOURCE_FILES main.cpp)

###################
#code directory
add_subdirectory("${PROJECT_SOURCE_DIR}/gui")
add_subdirectory("${PROJECT_SOURCE_DIR}/color_proc")


add_executable(ColorIt ${SOURCE_FILES})


include_directories("/usr/local/include")


###################
#Find Package
find_package(Qt5Core REQUIRED )
find_package(Qt5Widgets REQUIRED )
find_package(Qt5Gui REQUIRED )
find_package(OpenCV)



###################
#linking libraries

qt5_use_modules(ColorIt Core Widgets Gui )

target_link_libraries(ColorIt
        ${OpenCV_LIBRARIES}
)