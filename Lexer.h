#pragma once
#include <istream>
#include "Token.h"

class Lexer {
public:
    explicit Lexer(std::istream& input);
    Token nextToken(); // Main function to return next token

private:
    std::istream& in;
    char current{};
    bool eof = false;
    size_t line = 1, col = 0;

    void advance();
};
