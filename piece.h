#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <map>
#include <iterator>
#include <string>
#include <vector>

#include <iostream>

enum Owner {Human, Computer};


class Piece {
protected:
    unsigned int row;
    unsigned int col;
    Owner owner;
    std::vector<std::pair<unsigned int, unsigned int>> possibleMoves;
public:
    Piece(unsigned int row, unsigned int col, Owner player); // make protected
    unsigned int getRow();
    unsigned int getCol();

    std::vector<std::pair<unsigned int, unsigned int>> getPossibilities() {
        return possibleMoves;
    }

    Owner getOwner();
    bool isPossibleMove(std::pair<unsigned int, unsigned int> move);
    void movePiece(std::pair<unsigned int, unsigned int> next);

    void displayPossibilities() {
        for (int i =0; i < possibleMoves.size(); ++i) {
            std::cout << possibleMoves.at(i).first << ", " << possibleMoves.at(i).second << std::endl;
        }
    }

    virtual void updatePossibilities() = 0;
    virtual std::string getDisplay() = 0;
    virtual ~Piece() = default;
};


class King : public Piece {
public:
    King(unsigned int x, unsigned int y, Owner player);
    void updatePossibilities() override;
    std::string getDisplay() override;
};


class Queen : public Piece {
public:
    Queen(unsigned int x, unsigned int y, Owner player);
    void updatePossibilities() override;
    std::string getDisplay() override;
};


class Bishop : public Piece {
public:
    Bishop(unsigned int x, unsigned int y, Owner player);
    void updatePossibilities() override;
    std::string getDisplay() override;
};


class Knight : public Piece {
public:
    Knight(unsigned int x, unsigned int y, Owner player);
    void updatePossibilities() override;
    std::string getDisplay() override;
};


class Rook : public Piece {
public:
    Rook(unsigned int x, unsigned int y, Owner player);
    void updatePossibilities() override;
    std::string getDisplay() override;
};


class Pawn : public Piece {
public:
    Pawn(unsigned int x, unsigned int y, Owner player);
    void updatePossibilities() override;
    std::string getDisplay() override;
};


#endif
