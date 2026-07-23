// scanner.hpp
#pragma once
#include "token.hpp"
#include "tables.hpp"
#include "util.hpp"
#include <string_view>

class Scanner {
public:
    explicit Scanner(const std::string_view source) : src_(source) {}

    Token next() {
        //  skip whs and comments
        while (pos_ < src_.size()) {
            if (const CharClass cls = classifyChar(src_[pos_]); cls != CharClass::Ws) break;
            advance();
        }

        //  EOF
        if (pos_ >= src_.size()) {
            return Token{TokenType::Eof, "", line_, col_};
        }

        const size_t startPos  = pos_;
        const size_t startLine = line_;
        const size_t startCol  = col_;

        int state = 0;
        int lastAcceptState = -1;
        size_t lastAcceptPos  = pos_;
        size_t lastAcceptLine = line_;
        size_t lastAcceptCol  = col_;

        while (pos_ < src_.size()) {
            CharClass cls = classifyChar(src_[pos_]);
            if (cls == CharClass::Invalid) break;

            const int nextState = delta[state][static_cast<int>(cls)];
            if (nextState == DEAD) break;

            state = nextState;
            advance();

            if (accept[state]) {
                lastAcceptState = state;
                lastAcceptPos  = pos_;
                lastAcceptLine = line_;
                lastAcceptCol  = col_;
            }
        }

        //no accept: lexical error, consume exactly 1 char
        if (lastAcceptState == -1) {
            pos_ = startPos;
            line_ = startLine;
            col_ = startCol;
            const std::string_view badChar = src_.substr(startPos, 1);
            advance();
            return Token{TokenType::Error, badChar, startLine, startCol};
        }

        // rollback to last accepting point, pos, line, col all together
        pos_  = lastAcceptPos;
        line_ = lastAcceptLine;
        col_  = lastAcceptCol;

        const std::string_view lexeme = src_.substr(startPos, lastAcceptPos - startPos);
        TokenType type = tokenType[lastAcceptState];

        if (type == TokenType::Ident) {
            type = lookupKeyword(lexeme);
        }

        return Token{type, lexeme, startLine, startCol};
    }

private:
    std::string_view src_;
    size_t pos_ = 0;
    size_t line_ = 1;
    size_t col_ = 1;

    void advance() {
        if (src_[pos_] == '\n') {
            line_++;
            col_ = 1;
        } else {
            col_++;
        }
        pos_++;
    }
};