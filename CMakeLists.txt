cmake_minimum_required(VERSION 3.30)
project(LexicalAnalysis)

set(CMAKE_CXX_STANDARD 20)

add_executable(LexicalAnalysis main.cpp
        Token.h
        Lexer.h
        Lexer.cpp)
