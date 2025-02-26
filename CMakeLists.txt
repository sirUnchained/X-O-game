cmake_minimum_required(VERSION 3.0.0)
project(X_O_GAME VERSION 1.0.0)

add_subdirectory(print_dir)
add_subdirectory(action_dir)

add_executable(X_O_GAME 
  index.cpp
)

target_link_libraries(X_O_GAME
  print
  action
)