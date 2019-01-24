#include "human_player.h"


void HumanPlayer::move(Board * board) {
    throw NeedPlayerInput{};
}



void HumanPlayer::move(Position curr, Position next, Board * board) {
   /* if (!board->positionOnBoard(next)) {
        throw InvalidMove{"Square is not on board."};
    } else if (!board->getFromSquare(next)) {
        if (board->getFromSquare(next)->getOwner() == Owner::Human) {
            throw InvalidMove{"Square is occupied."};
        }
    } else if (!board->getFromSquare(curr)->isPossibleMove(next)) {
        std::string p = board->getFromSquare(curr)->getDisplay();
        throw InvalidMove{p + " can't be moved there."};
    }
*/
    // need to account for if player eats opponents piece, then return pointer to
    // eaten piece

    Piece * piece = board->getFromSquare(curr);
    board->fillSquare(piece, next);
    board->clearSquare(curr);
}