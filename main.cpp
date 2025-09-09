#include <iostream>
#include <fstream>
#include "Lexer.h"

//C++ 20
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cerr << "Error: cannot open file " << argv[1] << "\n";
        return 1;
    }

    Lexer lexer(fin);

    while (true) {
        Token t = lexer.nextToken();
        if (t.type == TokenType::EndOfFile) break;
        std::cout << static_cast<int>(t.type) << " " << t.lexeme << "\n";
    }
}
