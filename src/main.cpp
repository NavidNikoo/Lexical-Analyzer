// main.cpp — C++20
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Lexer.h"
#include "Token.h"

static const char* tokenTypeName(TokenType t) {
    switch (t) {
        case TokenType::Keyword:   return "keyword";
        case TokenType::Identifier:return "identifier";
        case TokenType::Integer:   return "integer";
        case TokenType::Real:      return "real";
        case TokenType::Operator:  return "operator";
        case TokenType::Separator: return "separator";
        case TokenType::String:    return "string";
        case TokenType::Unknown:   return "unknown";
        case TokenType::EndOfFile: return "EOF";
    }
    return "unknown";
}

static int process_one(const std::string& inPath, const std::string& outPath) {
    std::ifstream fin(inPath);
    if (!fin) {
        std::cerr << "Error: cannot open input file: " << inPath << "\n";
        return 1;
    }
    std::ofstream fout(outPath);
    if (!fout) {
        std::cerr << "Error: cannot open output file: " << outPath << "\n";
        return 1;
    }

    Lexer lexer(fin);
    fout << std::left << std::setw(12) << "token" << "lexeme\n";
    while (true) {
        Token t = lexer.nextToken();
        if (t.type == TokenType::EndOfFile) break;
        fout << std::left << std::setw(12) << tokenTypeName(t.type) << t.lexeme << '\n';
    }
    std::cout << "Wrote tokens to: " << outPath << "\n";
    return 0;
}

int main(int argc, char** argv) {
    // Accept multiple pairs: <in1> <out1> [<in2> <out2> ...]
    if (argc < 3 || (argc % 2) == 0) {
        std::cerr << "Usage: " << argv[0] << " <input1> <output1> [<input2> <output2> ...]\n";
        return 1;
    }
    int rc = 0;
    for (int i = 1; i + 1 < argc; i += 2) {
        rc |= process_one(argv[i], argv[i + 1]);
    }
    return rc;
}
