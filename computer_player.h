#ifndef CHESS_COMPUTER_PLAYER_H
#define CHESS_COMPUTER_PLAYER_H

#include "player.h"

class ComputerPlayer : public Player {
    int random = 9;
public:
    void move(Board * board) override;
    void move(std::pair<unsigned int, unsigned int> curr,
              std::pair<unsigned int, unsigned int> next, Board * board) override;
};


#endif