#include "board.h"


Board::Board() {
    std::vector<Piece*> topRow;
    topRow.push_back(new Rook{0, 0, Owner::Computer});
    topRow.push_back(new Knight{0, 1, Owner::Computer});
    topRow.push_back(new Bishop{0, 2, Owner::Computer});
    topRow.push_back(new Queen{0, 3, Owner::Computer});
    topRow.push_back(new King{0, 4, Owner::Computer});
    topRow.push_back(new Bishop{0, 5, Owner::Computer});
    topRow.push_back(new Knight{0, 6, Owner::Computer});
    topRow.push_back(new Rook{0, 7, Owner::Computer});
    board.push_back(topRow);

    std::vector<Piece*> topPawnRow;
    for (unsigned int col = 0; col < boardSize; ++col) {
        topPawnRow.push_back(new Pawn{1, col, Owner::Computer});
    }
    board.push_back(topPawnRow);

    for (unsigned int row = 2; row < boardSize - 2; ++row) {
        std::vector<Piece*> emptyRow;
        for (unsigned int col = 0; col < boardSize; ++col) {
            emptyRow.push_back(nullptr);
        }
        board.push_back(emptyRow);
    }

    std::vector<Piece*> bottomPawnRow;
    for (unsigned int col = 0; col < boardSize; ++col) {
        bottomPawnRow.push_back(new Pawn{6, col, Owner::Human});
    }
    board.push_back(bottomPawnRow);

    std::vector<Piece*> bottomRow;
    bottomRow.push_back(new Rook{7, 0, Owner::Human});
    bottomRow.push_back(new Knight{7, 1, Owner::Human});
    bottomRow.push_back(new Bishop{7, 2, Owner::Human});
    bottomRow.push_back(new Queen{7, 3, Owner::Human});
    bottomRow.push_back(new King{7, 4, Owner::Human});
    bottomRow.push_back(new Bishop{7, 5, Owner::Human});
    bottomRow.push_back(new Knight{7, 6, Owner::Human});
    bottomRow.push_back(new Rook{7, 7, Owner::Human});
    board.push_back(bottomRow);
}

Board::~Board() {
    for (unsigned int row = 0; row < boardSize; ++row) {
        for (unsigned int col = 0; col < boardSize; ++col) {
            delete board.at(row).at(col);
        }
    }
}


std::string Board::getDisplay() {
    std::string boardString = "     0    1    2    3    4    5    6    7\n";
    boardString += "   -----------------------------------------\n";
    for (unsigned int row = 0; row < boardSize; ++row) {
        boardString += std::to_string(row) + "  | ";
        for (unsigned int col = 0; col < boardSize; ++col) {
            Piece * p = board.at(row).at(col);
            std::string piece = p ? p->getDisplay() : "  ";
            boardString += piece + " | ";
        }
        boardString += "\n   -----------------------------------------\n";
    }
    return boardString;
}


bool Board::positionOnBoard(Position pos) {
    if (!((pos.first >= 0) && (pos.first <= 7))) return false;
    if (!((pos.second >= 0) && (pos.second <= 7))) return false;
    return true;
}


Piece * Board::getFromSquare(Position pos) {
    return board.at(pos.first).at(pos.second);
}


void Board::fillSquare(Piece * piece, Position pos) {
    board.at(pos.first).at(pos.second) = piece;
    piece->movePiece(pos);
    piece->updatePossibilities();
}


void Board::clearSquare(Position pos) {
    board.at(pos.first).at(pos.second) = nullptr;
}


void Board::filterPiecesPossibleMoves() {
    std::vector<Position> positions;
    for (auto & row : board) {
        for (auto piece : row) {
            if (piece) {
                positions.emplace_back(std::make_pair(piece->getRow(), piece->getCol()));
            }
        }
    }

    for (auto & row : board) {
        for (auto piece : row) {
            if (piece) {
                piece->filterPossibilities(positions);
            }
        }
    }
}