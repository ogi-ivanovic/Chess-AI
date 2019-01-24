#ifndef CHESS_COMPUTER_PLAYER_H
#define CHESS_COMPUTER_PLAYER_H

#include "player.h"

class ComputerPlayer : public Player {
    int random = 9;
public:
    void move(Board * board) override;
    void move(Position curr, Position next, Board * board) override;
};


#endif