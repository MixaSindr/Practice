#pragma once
#include "model.h"
#include "view.h"

class TicTacToeController {
public:
    TicTacToeController(TicTacToeModel& model, TicTacToeView& view);

    void startGame();
    void processMenu();
    void playRound();

private:
    TicTacToeModel& model;
    TicTacToeView& view;
};