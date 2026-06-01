cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    imageviewer
    VERSION 0.1.0
    DESCRIPTION "图片查看"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Gui)
include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    imageviewer_lib STATIC
    source/lib.cpp
    source/ui/ImageViewerWindow.cpp
)

target_link_libraries(imageviewer_lib PRIVATE Qt6::Widgets Qt6::Gui)

target_include_directories(
    imageviewer_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(imageviewer_lib PUBLIC cxx_std_17)

# ---- Declare executable ----

add_executable(imageviewer_exe source/main.cpp)
add_executable(imageviewer::exe ALIAS imageviewer_exe)

set_property(TARGET imageviewer_exe PROPERTY OUTPUT_NAME imageviewer)

target_compile_features(imageviewer_exe PRIVATE cxx_std_17)

target_link_libraries(imageviewer_exe PRIVATE imageviewer_lib)
target_link_libraries(imageviewer_exe PRIVATE Qt6::Widgets Qt6::Gui)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT imageviewer_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of imageviewer"
  )
endif()

include(cmake/dev-mode.cmake)
