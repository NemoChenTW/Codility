CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

# 使用資料夾名稱作為Project名稱
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
PROJECT(${ProjectId})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Using C++ 11
set(CMAKE_CXX_FLAGS		"-std=c++11")

# Append version flag
set(CMAKE_CXX_FLAGS		"${CMAKE_CXX_FLAGS} ${VER_FLAGS}")


AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR}/src ${ProjectId}_SRC)

include_directories(src)

IF(APPLE)
  SET(CMAKE_MACOSX_RPATH 0)
  # SET(CMAKE_INSTALL_NAME_DIR @executable_path)
  # SET(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
ENDIF(APPLE)

# # Use the c-build-tool parser to generated
# add_subdirectory(subl/dir/path)

# Generate Executable
add_executable(${ProjectId} ${${ProjectId}_SRC}) #執行檔名稱 + source
