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
    bool positionOnBoard(Position pos);
    Piece * getFromSquare(Position pos);
    std::vector<Position> getPiecePositions();
    void fillSquare(Piece * piece, Position pos);
    void clearSquare(Position pos);
    void filterPiecesPossibleMoves();
};


#endif
