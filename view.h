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
    virtual Position getCurrentPosition() = 0;
    virtual Position getNextPosition(Position curr) = 0;

    virtual void displayChooseOwnPiece() = 0;
};


#endif
