cmake_minimum_required(VERSION 3.10)
project(ExpenseTracker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
	add_compile_options(/W4 /WX)
else()
	add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_executable(expense-tracker ExpenseTracker/main.cpp)

target_include_directories(expense-tracker PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
