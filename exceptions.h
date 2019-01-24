#ifndef CHESS_EXCEPTIONS_H
#define CHESS_EXCEPTIONS_H


#include <string>

class NeedPlayerInput {};

class InvalidChoice {};

class InvalidMove {
    std::string message;
public:
    explicit InvalidMove(std::string message) : message{std::move(message)} {
    }

    std::string what() {
        return message;
    }
};


#endif
