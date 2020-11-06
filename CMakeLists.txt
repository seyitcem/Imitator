cmake_minimum_required(VERSION 3.16.3)

project(Imitator)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)
set(PROJECT_RESOURCE_DIR ${PROJECT_DIR}/res)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(PROJECT_RC_FILE
		${PROJECT_RESOURCE_DIR}/resources.rc
)
set(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
		${PROJECT_SOURCE_DIR}/Console.cpp
		${PROJECT_SOURCE_DIR}/Cursor.cpp
		${PROJECT_SOURCE_DIR}/File.cpp
		${PROJECT_SOURCE_DIR}/Keyboard.cpp
)
set(PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/main.hpp
		${PROJECT_INCLUDE_DIR}/Console.hpp
		${PROJECT_INCLUDE_DIR}/Cursor.hpp
		${PROJECT_INCLUDE_DIR}/File.hpp
		${PROJECT_INCLUDE_DIR}/Keyboard.hpp		
)
include_directories(
        ${PROJECT_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_RC_FILE})
target_link_libraries(${PROJECT_NAME})
