cmake_minimum_required(VERSION 3.5)

project(ffmpeg-qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Gui)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC src/*.cpp include/*.h src/*.ui)
file(GLOB_RECURSE QRC_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)

set(PROJECT_SOURCES ${SRC} ${QRC_SOURCE_FILES})



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# ffmpeg库依赖
# 设置ffmpeg依赖库及头文件所在目录，并存进指定变量
set(FFMPEG_LIBS_DIR /usr/lib)
set(FFMPEG_HEADERS_DIR /usr/include)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${FFMPEG_HEADERS_DIR}/libavcodec/avcodec.h
    ${FFMPEG_HEADERS_DIR}/libavfilter/avfilter.h
    ${FFMPEG_HEADERS_DIR}/libavformat/avformat.h
    ${FFMPEG_HEADERS_DIR}/libavutil/avutil.h
    ${FFMPEG_HEADERS_DIR}/libswresample/swresample.h
    ${FFMPEG_HEADERS_DIR}/libswscale/swscale.h)

#对于find_package找不到的外部依赖库，可以用add_library添加
# SHARED表示添加的是动态库
# IMPORTED表示是引入已经存在的动态库
add_library(avcodec SHARED IMPORTED)
#指定所添加依赖库的导入路径
set_target_properties(avcodec PROPERTIES IMPORTED_LOCATION ${FFMPEG_LIBS_DIR}/libavcodec.so)

add_library(avfilter SHARED IMPORTED)
set_target_properties(avfilter PROPERTIES IMPORTED_LOCATION ${FFMPEG_LIBS_DIR}/libavfilter.so)

add_library(avformat SHARED IMPORTED)
set_target_properties(avformat PROPERTIES IMPORTED_LOCATION ${FFMPEG_LIBS_DIR}/libavformat.so)

add_library(avutil SHARED IMPORTED)
set_target_properties(avutil PROPERTIES IMPORTED_LOCATION ${FFMPEG_LIBS_DIR}/libavutil.so)

add_library(swresample SHARED IMPORTED)
set_target_properties(swresample PROPERTIES IMPORTED_LOCATION ${FFMPEG_LIBS_DIR}/libswresample.so)

add_library(swscale SHARED IMPORTED)
set_target_properties(swscale PROPERTIES IMPORTED_LOCATION ${FFMPEG_LIBS_DIR}/libswscale.so)


target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets 
    Qt${QT_VERSION_MAJOR}::Gui
    # FFmpeg libs
    avcodec
    avfilter
    avformat
    avutil
    swresample
    swscale)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(${PROJECT_NAME})
    qt_finalize_executable(${PROJECT_NAME})
endif()
