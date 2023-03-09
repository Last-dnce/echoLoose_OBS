project(convbin)

cmake_minimum_required(VERSION 3.0)
# cmake_policy(SET CMP0015 NEW)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-std=c++11 -O0 -fPIC")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "-msse3")
set(CMAKE_C_FLAGS "-msse3")
set(CMAKE_C_FLAGS "-mavx")

# if("${CMAKE_BUILD_TYPE}" STREQUAL "")
#     SET(CMAKE_BUILD_TYPE "Release")
# endif()

## 添加头文件所在的目录
include_directories(
    # ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
)
# include_directories(${PYTHON_INCLUDE_DIRS})

file(GLOB SRC_FILES "src/*.cpp")

## 创建可执行程序的链接文件
add_library(Rtklib ${SRC_FILES})
# target_link_libraries(carvig blas lapack z pthread)

## 将libRtklib.a文件创建到/lib文件夹中
set_target_properties(Rtklib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY
                      ${PROJECT_SOURCE_DIR}/lib)

## 将Rtklib_Pos_exe可执行文件创建到/build文件夹中
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY
                       ${PROJECT_SOURCE_DIR}/build)

## 将rnx2rtkp.cpp作为主程序创建Rtklib_Pos_exe可执行文件，同时依赖已经创建的Rtklib链接库
add_executable(echoLoose_exe src/app/main.cpp)
target_link_libraries(echoLoose_exe Rtklib m)