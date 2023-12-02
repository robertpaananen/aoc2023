
cmake_minimum_required(VERSION 3.27)
project(day2)
add_executable(app)
target_sources(app PRIVATE code.c ../file/file.c)