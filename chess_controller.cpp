#include "chess_controller.h"


void ChessController::setNames(ChessModel & model, View & view) {
    std::string humanName = view.getName();
    model.setPlayerNames(humanName);
}


void ChessController::playGame(ChessModel & model, View & view) {
    view.displayBoard();
    unsigned int playerNum = 0;
    // make random later so the first to play changes every game
    while (!model.isGameDone()) {
        std::cout << "Player " << playerNum << "'s turn." << std::endl;
        int numberOfPlayers = model.getPlayer(0)->numAlivePieces() +
                              model.getPlayer(1)->numAlivePieces();
        std::cout << "Number of pieces: " << numberOfPlayers << std::endl;
        Position curr;
        Position next;
        try {
            model.getPlayer(playerNum)->move(model.getBoard()); // works only for computer
            view.displayBoard();
        } catch (NeedPlayerInput & input) {
            while (true) {
                try {
                    curr = view.getCurrentPosition();
                    break;
                } catch (InvalidChoice & choice) {
                    view.displayChooseOwnPiece();
                }
            }

            model.getBoard()->getFromSquare(curr)->displayPossibilities();

            while (true) {
                try {
                    next = view.getNextPosition(curr);
                    break;
                } catch (InvalidMove & move) {
                    std::cout << move.what() << std::endl;
                }
            }
            //model.getPlayer(playerNum)->move(curr, next, model.getBoard());
            model.humanMove(curr, next);
            view.displayBoard(); // remove later once computer player is added
        }
        playerNum = (playerNum + 1) % 2;
    }
}
