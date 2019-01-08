#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <algorithm>

#include "board.h"
#include "exceptions.h"

class Player {
protected:
    std::string name;
    std::vector<Piece*> alivePieces;
    std::vector<Piece*> deadPieces;
public:
    void addAlivePiece(Piece * p);
    void addDeadPiece(Piece * p);
    bool isPlayersPiece(Piece * p);
    void setName(const std::string & name);
    int numAlivePieces() { // delete later once done debugging
        return alivePieces.size();
    }
    virtual ~Player();
    virtual void move(Board * board) = 0;
    virtual void move(std::pair<unsigned int, unsigned int> curr,
              std::pair<unsigned int, unsigned int> next, Board * board) = 0;
};


#endif
