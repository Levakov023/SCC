#pragma once
#include "token.hpp"

enum class CharClass {
    Letter, Digit19, Zero,
    Plus, Minus, Star,
    Slash, Lt, Gt,
    Eq, Ws, Invalid
};

// needed to
inline CharClass classifyChar( const char ch ) {

    if ( ch>= 'a' && ch <= 'z' ) return CharClass::Letter;
    if ( ch == '0' ) return CharClass::Zero;
    if ( ch >= '1' && ch <= '9' ) return CharClass::Digit19;
    if ( ch == '+' ) return CharClass::Plus;
    if ( ch == '-' ) return CharClass::Minus;
    if ( ch == '*' ) return CharClass::Star;
    if ( ch == '/' ) return CharClass::Slash;
    if ( ch == '<' ) return CharClass::Lt;
    if ( ch == '>' ) return CharClass::Gt;
    if ( ch == '=' ) return CharClass::Eq;
    if ( ch == ' ' || ch == '\t' || ch == '\n' ) return CharClass::Ws;
    return CharClass::Invalid;

}

inline TokenType lookupKeyword(const std::string_view lexeme ) {

    if ( lexeme == "if" ) return TokenType::If;
    if ( lexeme == "while" ) return TokenType::While;
    if ( lexeme == "return" ) return TokenType::Return;

    return TokenType::Ident;

}

