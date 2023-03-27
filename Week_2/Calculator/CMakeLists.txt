cmake_minimum_required(VERSION 3.0.0)
project(Calculator VERSION 0.1.0)

include(CTest)
enable_testing()

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Release") # 产物目录
include_directories("${PROJECT_SOURCE_DIR}/Headers")  # 头文件目录
aux_source_directory(${PROJECT_SOURCE_DIR}/Sources DIR_SRCS)


add_executable(Calculator ${DIR_SRCS})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
