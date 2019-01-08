#include "piece.h"
#include "board.h"

////////////////////////// Base Piece //////////////////////////

Piece::Piece(unsigned int row, unsigned int col, Owner player) :
    row{row}, col{col}, owner{player} {
}


unsigned int Piece::getRow() {
    return row;
}


unsigned int Piece::getCol() {
    return col;
}


Owner Piece::getOwner() {
    return owner;
}


bool Piece::isPossibleMove(std::pair<unsigned int, unsigned int> move) {
    for (auto itr : possibleMoves) {
        if (move == itr) {
            return true;
        }
    }
    return false;
}


void Piece::movePiece(std::pair<unsigned int, unsigned int> next) {
    row = next.first;
    col = next.second;
}

///////////////////////////////////////////////////////////////

King::King(unsigned int row, unsigned int col, Owner player) :
    Piece{row, col, player} {
    updatePossibilities();
}


void King::updatePossibilities() {
    // add caste move possibility later
    possibleMoves.clear();
    if (row >= 1) { // up
        std::pair<unsigned int, unsigned int> pos(row - 1, col);
        possibleMoves.emplace_back(pos);
    }
    if (row < boardSize - 1) { // down
        std::pair<unsigned int, unsigned int> pos(row + 1, col);
        possibleMoves.emplace_back(pos);
    }
    if (col >= 1) { // left
        std::pair<unsigned int, unsigned int> pos(row, col - 1);
        possibleMoves.emplace_back(pos);
    }
    if (col < boardSize - 1) { // right
        std::pair<unsigned int, unsigned int> pos(row, col + 1);
        possibleMoves.emplace_back(pos);
    }
    if ((row >= 1) && (col >= 1)) { // up & left
        std::pair<unsigned int, unsigned int> pos(row - 1, col - 1);
        possibleMoves.emplace_back(pos);
    }
    if ((row >= 1) && (col < boardSize - 1)) { // up & right
        std::pair<unsigned int, unsigned int> pos(row - 1, col + 1);
        possibleMoves.emplace_back(pos);
    }
    if ((row < boardSize - 1) && (col >= 1)) { // down & left
        std::pair<unsigned int, unsigned int> pos(row + 1, col - 1);
        possibleMoves.emplace_back(pos);
    }
    if ((row < boardSize - 1) && (col < boardSize - 1)) { // down & right
        std::pair<unsigned int, unsigned int> pos(row + 1, col + 1);
        possibleMoves.emplace_back(pos);
    }
}


std::string King::getDisplay() {
    if (owner == Owner::Human) {
        return "K0";
    } else {
        return "K1";
    }
}

///////////////////////////////////////////////////////////////

Queen::Queen(unsigned int row, unsigned int col, Owner player) :
    Piece{row, col, player} {
    updatePossibilities();
}


void Queen::updatePossibilities() {
    possibleMoves.clear();
    int tempRow = row - 1;
    while (tempRow >= 0) { // up
        std::pair<unsigned int, unsigned int> pos (tempRow, col);
        possibleMoves.emplace_back(pos);
        --tempRow;
    }
    tempRow = row + 1;
    while (tempRow < boardSize) { // down
        std::pair<unsigned int, unsigned int> pos (tempRow, col);
        possibleMoves.emplace_back(pos);
        ++tempRow;
    }
    int tempCol = col - 1;
    while (tempCol >= 0) { // left
        std::pair<unsigned int, unsigned int> pos (row, tempCol);
        possibleMoves.emplace_back(pos);
        --tempCol;
    }
    tempCol = col + 1;
    while (tempCol < boardSize) { // right
        std::pair<unsigned int, unsigned int> pos (row, tempCol);
        possibleMoves.emplace_back(pos);
        ++tempCol;
    }

    tempRow = row - 1;
    tempCol = col - 1;
    while ((tempRow >= 0) && (tempCol >= 0)) { // up & left
        std::pair<unsigned int, unsigned int> pos(tempRow, tempCol);
        possibleMoves.emplace_back(pos);
        --tempRow;
        --tempCol;
    }
    tempRow = row - 1;
    tempCol = col + 1;
    while ((tempRow >= 0) && (tempCol < boardSize)) { // up & right
        std::pair<unsigned int, unsigned int> pos(tempRow, tempCol);
        possibleMoves.emplace_back(pos);
        --tempRow;
        ++tempCol;
    }
    tempRow = row + 1;
    tempCol = col - 1;
    while ((tempRow < boardSize) && (tempCol >= 0)) { // down & left
        std::pair<unsigned int, unsigned int> pos(tempRow, tempCol);
        possibleMoves.emplace_back(pos);
        ++tempRow;
        --tempCol;
    }
    tempRow = row + 1;
    tempCol = col + 1;
    while ((tempRow <boardSize) && (tempCol < boardSize)) { // down & right
        std::pair<unsigned int, unsigned int> pos(tempRow, tempCol);
        possibleMoves.emplace_back(pos);
        ++tempRow;
        ++tempCol;
    }

}


std::string Queen::getDisplay() {
    if (owner == Owner::Human) {
        return "Q0";
    } else {
        return "Q1";
    }
}

///////////////////////////////////////////////////////////////

Bishop::Bishop(unsigned int row, unsigned int col, Owner player) :
    Piece{row, col, player} {
    updatePossibilities();
}


void Bishop::updatePossibilities() {
    possibleMoves.clear();
    int tempRow = row - 1;
    int tempCol = col - 1;
    while ((tempRow >= 0) && (tempCol >= 0)) { // up & left
        std::pair<unsigned int, unsigned int> pos(tempRow, tempCol);
        possibleMoves.emplace_back(pos);
        --tempRow;
        --tempCol;
    }
    tempRow = row - 1;
    tempCol = col + 1;
    while ((tempRow >= 0) && (tempCol < boardSize)) { // up & right
        std::pair<unsigned int, unsigned int> pos(tempRow, tempCol);
        possibleMoves.emplace_back(pos);
        --tempRow;
        ++tempCol;
    }
    tempRow = row + 1;
    tempCol = col - 1;
    while ((tempRow < boardSize) && (tempCol >= 0)) { // down & left
        std::pair<unsigned int, unsigned int> pos(tempRow, tempCol);
        possibleMoves.emplace_back(pos);
        ++tempRow;
        --tempCol;
    }
    tempRow = row + 1;
    tempCol = col + 1;
    while ((tempRow <boardSize) && (tempCol < boardSize)) { // down & right
        std::pair<unsigned int, unsigned int> pos(tempRow, tempCol);
        possibleMoves.emplace_back(pos);
        ++tempRow;
        ++tempCol;
    }
}


std::string Bishop::getDisplay() {
    if (owner == Owner::Human) {
        return "b0";
    } else {
        return "b1";
    }
}

///////////////////////////////////////////////////////////////

Knight::Knight(unsigned int row, unsigned int col, Owner player) :
    Piece{row, col, player} {
    updatePossibilities();
}


void Knight::updatePossibilities() {
    possibleMoves.clear();
    if ((row >= 2) && (col >= 1)) { // up & left 1
        std::pair<unsigned int, unsigned int> pos (row - 2, col - 1);
        possibleMoves.emplace_back(pos);
    }
    if ((row >= 2) && (col < boardSize - 1)) { // up & right 1
        std::pair<unsigned int, unsigned int> pos (row - 2, col + 1);
        possibleMoves.emplace_back(pos);
    }
    if ((row < boardSize - 2) && (col >= 1)) { // down & left 1
        std::pair<unsigned int, unsigned int> pos (row + 2, col - 1);
        possibleMoves.emplace_back(pos);
    }
    if ((row < boardSize - 2) && (col < boardSize - 1)) { // down & right 1
        std::pair<unsigned int, unsigned int> pos (row + 2, col + 1);
        possibleMoves.emplace_back(pos);
    }

    if ((row >= 1) && (col >= 2)) { // up & left 2
        std::pair<unsigned int, unsigned int> pos (row, col);
        possibleMoves.emplace_back(pos);
    }
    if ((row >= 1) && (col < boardSize - 2)) { // up & right 2
        std::pair<unsigned int, unsigned int> pos (row - 1, col + 2);
        possibleMoves.emplace_back(pos);
    }
    if ((row < boardSize - 1) && (col >= 2)) { // down & left 2
        std::pair<unsigned int, unsigned int> pos (row + 1, col - 2);
        possibleMoves.emplace_back(pos);
    }
    if ((row < boardSize - 1) && (col < boardSize - 2)) { // down & right 2
        std::pair<unsigned int, unsigned int> pos (row + 1, col + 2);
        possibleMoves.emplace_back(pos);
    }
}


std::string Knight::getDisplay() {
    if (owner == Owner::Human) {
        return "k0";
    } else {
        return "k1";
    }
}

///////////////////////////////////////////////////////////////

Rook::Rook(unsigned int row, unsigned int col, Owner player) :
    Piece{row, col, player} {
    updatePossibilities();
}


void Rook::updatePossibilities() {
    possibleMoves.clear();
    int tempRow = row - 1;
    while (tempRow >= 0) { // up
        std::pair<unsigned int, unsigned int> pos (tempRow, col);
        possibleMoves.emplace_back(pos);
        --tempRow;
    }
    tempRow = row + 1;
    while (tempRow < boardSize) { // down
        std::pair<unsigned int, unsigned int> pos (tempRow, col);
        possibleMoves.emplace_back(pos);
        ++tempRow;
    }
    int tempCol = col - 1;
    while (tempCol >= 0) { // left
        std::pair<unsigned int, unsigned int> pos (row, tempCol);
        possibleMoves.emplace_back(pos);
        --tempCol;
    }
    tempCol = col + 1;
    while (tempCol < boardSize) { // right
        std::pair<unsigned int, unsigned int> pos (row, tempCol);
        possibleMoves.emplace_back(pos);
        ++tempCol;
    }
}


std::string Rook::getDisplay() {
    if (owner == Owner::Human) {
        return "r0";
    } else {
        return "r1";
    }
}

///////////////////////////////////////////////////////////////

Pawn::Pawn(unsigned int row, unsigned int col, Owner player) :
    Piece{row, col, player} {
    if (row == 6) { // CHANGE TO player == Owner::Human ONCE AI IS WORKING
        std::pair<unsigned int, unsigned int> upOne (row - 1, col);
        std::pair<unsigned int, unsigned int> upTwo (row - 2, col);
        possibleMoves.emplace_back(upOne);
        possibleMoves.emplace_back(upTwo);
    } else {
        std::pair<unsigned int, unsigned int> downOne (row + 1, col);
        std::pair<unsigned int, unsigned int> downTwo (row + 2, col);
        possibleMoves.emplace_back(downOne);
        possibleMoves.emplace_back(downTwo);
    }
}


void Pawn::updatePossibilities() {
    possibleMoves.clear();
    // ADDDDDDDDD && OWNER::PLAYER STUFF TO CHECK CAUSE U CAN ONLY HAVE UP TO ONE
    // POSSIBLE MOVE FOR A PAWN OTHER THAN AT START
    if (row >= 1) { // up
        std::pair<unsigned int, unsigned int> pos (row - 1, col);
        possibleMoves.emplace_back(pos);
    }
    if (row < boardSize - 1) {
        std::pair<unsigned int, unsigned int> pos (row + 1, col);
        possibleMoves.emplace_back(pos);
    }
}


std::string Pawn::getDisplay() {
    if (owner == Owner::Human) {
        return "p0";
    } else {
        return "p1";
    }
}
