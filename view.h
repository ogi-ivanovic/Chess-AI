#ifndef CHESS_VIEW_H
#define CHESS_VIEW_H

#include <iostream>

#include "chess_model.h"

class View {
protected:
    ChessModel * model;
public:
    explicit View(ChessModel * model);

    virtual void displayBoard() const = 0;

    // need to check for invalid input later
    virtual std::string getName() = 0;
    virtual std::pair<unsigned int, unsigned int> getCurrentPosition() = 0;
    virtual std::pair<unsigned int, unsigned int> getNextPosition(
            std::pair<unsigned int, unsigned int> curr) = 0;
};


#endif
