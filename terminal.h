#ifndef CHESS_TERMINAL_H
#define CHESS_TERMINAL_H

#include "view.h"

class Terminal : public View {
public:
    explicit Terminal(ChessModel * model);

    void displayBoard() const override;

    std::string getName() override;
    std::pair<unsigned int, unsigned int> getCurrentPosition() override;
    std::pair<unsigned int, unsigned int> getNextPosition(
            std::pair<unsigned int, unsigned int> curr) override;
};


#endif