cmake_minimum_required(VERSION 3.5)

project(MoyuReader VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 Qt5 包
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# 设置源文件
set(SOURCES
  main.cpp
  home.cpp
  systemtray.cpp
)

set(HEADERS
  home.h
  systemtray.h
)

# Qt 的 UI、MOC、资源文件支持
qt5_wrap_ui(UIS_H ${UIS})
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

add_executable(${PROJECT_NAME}
  ${SOURCES}
  ${MOC_SOURCES}
  ${UIS_H}
)

# 链接 Qt5 Widgets
target_link_libraries(${PROJECT_NAME}
  Qt5::Widgets
)

# Qt 6
# find_package(Qt6 REQUIRED COMPONENTS Widgets)
# target_link_libraries(${PROJECT_NAME} Qt6::Widgets)

