cmake_minimum_required(VERSION 3.10)
project(ExpenseTracker VERSION 0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_NAME expense-tracker)

if(MSVC)
	add_compile_options(/W4 /WX)
else()
	add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

find_package(unofficial-getopt-win32 REQUIRED) # whyyyyyyyyyyyyyyyyyyyyyyyy
    
add_executable(${EXECUTABLE_NAME} ExpenseTracker/main.cpp)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE unofficial::getopt-win32::getopt) # sooooooooooooo unintuitive

target_include_directories(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set the data file path relative to the executable
if(WIN32)
    set(DATA_FILE "\"data.json\"")  # Windows: same directory as exe
else()
    set(DATA_FILE "\"../data/data.json\"")  # Linux: relative to build dir
endif()

target_compile_definitions(${EXECUTABLE_NAME} PRIVATE 
    DATA_FILE_PATH=${DATA_FILE}
)