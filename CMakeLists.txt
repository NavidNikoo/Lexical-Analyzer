cmake_minimum_required(VERSION 3.20)
project(LexicalAnalysis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LexicalAnalysis
        src/main.cpp
        src/Lexer.cpp
)

# If Token.h and Lexer.h are in src/, let the compiler find them:
target_include_directories(LexicalAnalysis PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
