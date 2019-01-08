#ifndef CHESS_CHESS_CONTROLLER_H
#define CHESS_CHESS_CONTROLLER_H

#include "chess_model.h"
#include "view.h"

class ChessController {
public:
    void setNames(ChessModel & model, View & view);
    void playGame(ChessModel & model, View & view);

};


#endif