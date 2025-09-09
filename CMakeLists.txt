cmake_minimum_required(VERSION 3.10)

# Project name and language
project(LambdaApp LANGUAGES CXX)

# Set C++ standard to GNU C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Add the app executable
add_executable(lambda_app app/main.cpp)

# Enable warnings
if (MSVC)
  target_compile_options(lambda_app PRIVATE /W4)
else()
  target_compile_options(lambda_app PRIVATE -Wall -Wextra -pedantic)