#include "player.h"


void Player::addAlivePiece(Piece * p) {
    alivePieces.emplace_back(p);
}

void Player::addDeadPiece(Piece * p) {
    alivePieces.erase(std::remove(alivePieces.begin(), alivePieces.end(), p),
            alivePieces.end());
    deadPieces.emplace_back(p);
}

bool Player::isPlayersPiece(Piece * p) {
    return (std::find(alivePieces.begin(), alivePieces.end(), p) != alivePieces.end());
}


void Player::setName(const std::string & name) {
    this->name = name;
}


Player::~Player() {
    for (auto itr : deadPieces) {
        delete itr;
    }
}
