#include <iostream>

#include "chess_controller.h"
#include "terminal.h"

int main() {
    ChessModel model{};
    Terminal view{&model};
    ChessController controller;

    controller.playGame(model, view);
}
