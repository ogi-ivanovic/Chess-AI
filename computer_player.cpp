#include "computer_player.h"


void ComputerPlayer::move(Board * board) {
    Piece * piece;
    Position curr;
    Position next;
    bool found = false;

    for (int i = 0; i < alivePieces.size(); ++i) {
        piece = alivePieces.at(i);
        std::vector<Position> possibilities;
        possibilities = piece->getPossibilities();
        for (int j = 0; j < possibilities.size(); ++j) {
            if (!(board->getFromSquare(possibilities.at(j)))) {
                curr = std::make_pair(piece->getRow(), piece->getCol());
                next = possibilities.at(j);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    board->fillSquare(piece, next);
    board->clearSquare(curr);
}


// do not need this method
void ComputerPlayer::move(Position curr, Position next, Board * board) {

}
