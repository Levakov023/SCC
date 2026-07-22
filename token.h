
#ifndef SCANNER_TOKEN_H
#define SCANNER_TOKEN_H
#include <string_view>

enum class TokenType {
    Ident, IntLit, Plus, Minus, Star, Slash, Assign,
    Eq, Le, Ge, Lt, Gt, If, While, Return, Eof, Error
};

struct Token {
    TokenType type;
    std::string_view lexeme;
    std::size_t line;
    std::size_t col;

};

#endif //SCANNER_TOKEN_H
