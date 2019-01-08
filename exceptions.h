#ifndef CHESS_EXCEPTIONS_H
#define CHESS_EXCEPTIONS_H


#include <string>

class NeedPlayerInput {};

class InvalidChoice {};

class InvalidMove {
    std::string message;
public:
    explicit InvalidMove(const std::string & message) : message{message} {
    }

    std::string what() {
        return message;
    }
};


#endif
