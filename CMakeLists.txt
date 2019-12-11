cmake_minimum_required(VERSION 3.15)

project(Qdip LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES
    ${SRC_DIR}/implement/*.cpp
    ${SRC_DIR}/implement/process/*.cpp)
file(GLOB_RECURSE HEADERS
    ${SRC_DIR}/include/*.h
    ${SRC_DIR}/include/process/*.h)
file(GLOB_RECURSE FORMS ${SRC_DIR}/resource/*.ui)
file(GLOB_RECURSE RESOURCES ${SRC_DIR}/resource/*.qrc)

set(SRC_FILES main.cpp ${SOURCES} ${HEADERS} ${FORMS} ${RESOURCES})
set(QT_PKGS Core Quick)
set(QT_LIBS Qt5::Core Qt5::Quick)

find_package(Qt5 COMPONENTS ${QT_PKGS} REQUIRED)

# OpenCV
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

# Boost
find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})

if(ANDROID)
    add_library(Qdip SHARED ${SRC_FILES})
else()
    add_executable(${PROJECT_NAME} ${SRC_FILES})
endif()

target_compile_definitions(Qdip
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Qdip
  PRIVATE ${QT_LIBS} ${OpenCV_LIBS} ${Boost_LIBRARIES})

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# These variables must use CACHE, otherwise QtCreator won't see them.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android" CACHE INTERNAL "")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so CACHE INTERNAL "")
#    endif()
#endif()
