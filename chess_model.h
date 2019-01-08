#ifndef CHESS_CHESS_MODEL_H
#define CHESS_CHESS_MODEL_H

#include "human_player.h"
#include "computer_player.h"

class ChessModel {
    Board * board;
    bool gameDone;
    std::vector<Player*> players; // 0: human, 1: computer BOTH HUMANS 4 NOW

    void attack(std::pair<unsigned int, unsigned int> hunter,
            std::pair<unsigned int, unsigned int> prey);
public:
    ChessModel();
    ~ChessModel();
    void setPlayerNames(const std::string & humanName);
    void humanMove(std::pair<unsigned int, unsigned int> curr,
              std::pair<unsigned int, unsigned int> next);
    bool isPlayersPiece(std::pair<unsigned int, unsigned int> curr, Owner owner);
    Player * getPlayer(unsigned int playerNum);
    Board * getBoard();
    bool isGameDone();
};


#endif
