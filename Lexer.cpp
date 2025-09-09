#include "Lexer.h"
#include <cctype>

Lexer::Lexer(std::istream& input) : in(input) {
    advance(); // Load first character
}

void Lexer::advance() {
    int ch = in.get();
    if (ch == EOF) {
        eof = true;
        current = '\0';
        return;
    }
    current = static_cast<char>(ch);
    if (current == '\n') { line++; col = 0; }
    else { col++; }
}

Token Lexer::nextToken() {
    // Placeholder: skip whitespace
    while (!eof && std::isspace(static_cast<unsigned char>(current))) {
        advance();
    }

    if (eof) {
        return { TokenType::EndOfFile, "", line, col };
    }

    // For now: return one char as Unknown
    char ch = current;
    advance();
    return { TokenType::Unknown, std::string(1, ch), line, col };
}
