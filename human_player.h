#ifndef CHESS_HUMAN_H
#define CHESS_HUMAN_H

#include "player.h"

class HumanPlayer : public Player {
public:
    void move(Board * board) override;
    void move(std::pair<unsigned int, unsigned int> curr,
              std::pair<unsigned int, unsigned int> next, Board * board) override;
};


#endif
