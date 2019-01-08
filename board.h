#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>

#include "piece.h"

const int boardSize = 8;

class Board {
    std::vector<std::vector<Piece*>> board;
public:
    Board();
    ~Board(); // delete pieces from board
    std::string getDisplay(); // returns a string of the board
    bool positionOnBoard(std::pair<unsigned int, unsigned int> pos);
    Piece * getFromSquare(std::pair<unsigned int, unsigned int> pos);
    void fillSquare(Piece * piece, std::pair<unsigned int, unsigned int> pos);
    void clearSquare(std::pair<unsigned int, unsigned int> pos);
};


#endif
