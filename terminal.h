#ifndef CHESS_TERMINAL_H
#define CHESS_TERMINAL_H

#include "view.h"

class Terminal : public View {
public:
    explicit Terminal(ChessModel * model);

    void displayBoard() const override;
    void displayChooseOwnPiece() override;

    std::string getName() override;
    Position getCurrentPosition() override;
    Position getNextPosition(Position curr) override;
};


#endif