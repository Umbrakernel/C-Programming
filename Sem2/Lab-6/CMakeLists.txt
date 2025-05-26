cmake_minimum_required(VERSION 3.10)
project(StudentSort)

option(BUILD_STATIC "Build static library" ON)
option(BUILD_SHARED "Build shared library" OFF)

add_library(student_objects OBJECT 
    student.c
    sort.c
)

if(BUILD_STATIC)
    add_library(student_static STATIC $<TARGET_OBJECTS:student_objects>)
    set_target_properties(student_static PROPERTIES OUTPUT_NAME "student")
endif()

if(BUILD_SHARED)
    add_library(student_shared SHARED $<TARGET_OBJECTS:student_objects>)
    set_target_properties(student_shared PROPERTIES OUTPUT_NAME "student")
endif()

add_executable(student_program main.c)
target_include_directories(student_program PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_STATIC)
    target_link_libraries(student_program student_static)
elseif(BUILD_SHARED)
    target_link_libraries(student_program student_shared)
endif()