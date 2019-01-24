#include "terminal.h"


Terminal::Terminal(ChessModel * model) :
    View{model} {
}


std::string Terminal::getName() {
    std::string name;
    std::cin >> name;
    return name;
}


Position Terminal::getCurrentPosition() {
    std::cout << "Current piece position: ";
    unsigned int currRow, currCol;
    if (!(std::cin >> currRow)) {
        throw InvalidChoice{};
    }
    if (!(std::cin >> currCol)) {
        throw InvalidChoice{};
    }
    Position curr(currRow, currCol);
    if (!(model->getBoard()->positionOnBoard(curr))) {
        throw InvalidChoice{};
    } else if (!(model->isPlayersPiece(curr, Owner::Human))) {
        throw InvalidChoice{};
    }
    return curr;
}


Position Terminal::getNextPosition(Position curr) {
    std::cout << "Desired piece position: ";
    unsigned int nextRow, nextCol;
    if (!(std::cin >> nextRow)) {
        throw InvalidMove{"Incorrect input."};
    }
    if (!(std::cin >> nextCol)) {
        throw InvalidMove{"Incorrect input."};
    }
    Position next(nextRow, nextCol);
    if (!(model->getBoard()->positionOnBoard(next))) {
        throw InvalidMove{"Square is not on board."};
    } else if (model->getBoard()->getFromSquare(next) != nullptr) {
        if (model->getBoard()->getFromSquare(next)->getOwner() == Owner::Human) {
            throw InvalidMove{"Square is occupied."};
        }
    } else if (!(model->getBoard()->getFromSquare(curr)->isPossibleMove(next))) {
        std::string p = model->getBoard()->getFromSquare(curr)->getDisplay();
        throw InvalidMove{p + " can't be moved there."};
    }
    return next;
}

////////////////// DISPLAY METHODS //////////////////

void Terminal::displayBoard() const {
    std::cout << model->getBoard()->getDisplay();
}


void Terminal::displayChooseOwnPiece() {
    std::cout << "You must choose one of your pieces." << std::endl;
}
