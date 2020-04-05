cmake_minimum_required(VERSION 3.15)
project(playground)

set(CMAKE_CXX_STANDARD 14)

add_executable(playground main.cpp)
add_executable(ref_test ref_test.cpp)
add_executable(person person.cpp person.hpp)
add_executable(static_params static_parameters.cpp object.hpp)
add_executable(creating_sharing_resources swapping_and_copying.cpp RAII.h)
add_executable(polymorph friend_overload.cpp friend_overload.h)
add_executable(sets sets.cpp )
add_executable(template_functions template_functions.cpp templates.h object.hpp)
add_executable(moving_targets my_moving_target.cpp templates.h object.hpp)