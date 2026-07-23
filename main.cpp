// main.cpp
#include "Scanner/scanner.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
#include <filesystem>

namespace fs = std::filesystem;

const char* tokenTypeName(const TokenType t) {
    switch (t) {
        case TokenType::Ident:   return "Ident";
        case TokenType::IntLit:  return "IntLit";
        case TokenType::Plus:    return "Plus";
        case TokenType::Minus:   return "Minus";
        case TokenType::Star:    return "Star";
        case TokenType::Slash:   return "Slash";
        case TokenType::Assign:  return "Assign";
        case TokenType::Eq:      return "Eq";
        case TokenType::Le:      return "Le";
        case TokenType::Ge:      return "Ge";
        case TokenType::Lt:      return "Lt";
        case TokenType::Gt:      return "Gt";
        case TokenType::If:      return "If";
        case TokenType::While:   return "While";
        case TokenType::Return:  return "Return";
        case TokenType::Eof:     return "Eof";
        case TokenType::Error:   return "Error";
        default:                 return "None";
    }
}

void runTest(std::ostream& out, const std::string_view label, const std::string_view source) {
    out << "--- " << label << " ---\n";
    Scanner scanner(source);
    while (true) {
        auto [type, lexeme, line, col] = scanner.next();
        out << "  " << tokenTypeName(type)
            << " \"" << lexeme << "\""
            << " (line " << line << ", col " << col << ")\n";
        if (type == TokenType::Eof) break;
    }
    out << "\n";
}

int main() {
    const fs::path outDir = fs::path(__FILE__).parent_path() / "output";
    fs::create_directories(outDir); // creates output/ if  doesnt exist


    const fs::path outPath = outDir / "logx.log";
    std::ofstream logFile(outPath);
    if (!logFile) {
        std::cerr << "Failed to open log file at " << outPath << "\n";
        return 1;
    }

    runTest(logFile, "normal input", "x = 5 + y;");
    runTest(logFile, "keyword/ident collision", "iff");
    runTest(logFile, "rollback case", "12.3.4");
    runTest(logFile, "invalid char", "x = @ 5;");

    logFile.close();
    std::cout << "Output written to " << outPath << "\n";
    return 0;
}