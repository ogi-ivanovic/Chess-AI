#include "chess_model.h"


void ChessModel::attack(std::pair<unsigned int, unsigned int> hunterPos,
            std::pair<unsigned int, unsigned int> preyPos) {
    unsigned int preyPlayerNum;
    Piece * hunter = board->getFromSquare(hunterPos);
    Piece * prey = board->getFromSquare(preyPos);
    if (hunter->getOwner() == Owner::Human) {
        preyPlayerNum = 1;
    } else {
        preyPlayerNum = 0;
    }
    players.at(preyPlayerNum)->addDeadPiece(prey);
    board->fillSquare(hunter, preyPos);
    board->clearSquare(hunterPos);
}


ChessModel::ChessModel() :
    board{new Board{}}, gameDone{false} {
    players.emplace_back(new HumanPlayer{});
    players.emplace_back(new ComputerPlayer{});
    for (unsigned int row = 0; row < boardSize; ++row) {
        for (unsigned int col = 0; col < boardSize; ++col) {
            std::pair<unsigned int, unsigned int> pos(row, col);
            Piece * piece = board->getFromSquare(pos);
            if (piece) {
                if (piece->getOwner() == Owner::Human) {
                    players.at(0)->addAlivePiece(piece);
                } else {
                    players.at(1)->addAlivePiece(piece);
                }
            }
        }
    }
}


ChessModel::~ChessModel() {
    delete players.at(0);
    delete players.at(1);
}


void ChessModel::setPlayerNames(const std::string & humanName) {
    players.at(0)->setName(humanName);
    players.at(0)->setName("Computer");
}


// we already checked in the view if the chosen positions are valid
void ChessModel::humanMove(std::pair<unsigned int, unsigned int> curr,
          std::pair<unsigned int, unsigned int> next) {

    // attack
    if (board->getFromSquare(next)) {
        if (board->getFromSquare(next)->getOwner() == Owner::Computer) {
            attack(curr, next);
        }
    } else {
        Piece * piece = board->getFromSquare(curr);
        board->fillSquare(piece, next);
        board->clearSquare(curr);
    }
}


bool ChessModel::isPlayersPiece(std::pair<unsigned int, unsigned int> curr,
        Owner owner) {
    Player * player;
    if (owner == Owner::Human) {
        player = players.at(0);
    } else {
        player = players.at(1);
    }
    Piece * piece = board->getFromSquare(curr);
    return player->isPlayersPiece(piece);
}


Player * ChessModel::getPlayer(unsigned int playerNum) {
    return players.at(playerNum);
}


Board * ChessModel::getBoard() {
    return board;
}

bool ChessModel::isGameDone() {
    return gameDone;
}
