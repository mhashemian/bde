cmake_minimum_required (VERSION 3.15)
project (ball_init)

find_package(Threads REQUIRED)
find_package(bal REQUIRED)
find_package(bdl REQUIRED)
find_package(bsl REQUIRED)

add_executable(ball_init ball_init.cpp)
target_link_libraries(ball_init bal bdl bsl Threads::Threads rt)
