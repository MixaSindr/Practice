#include "model.h"
#include "view.h"
#include "controller.h"

int main() {
    TicTacToeModel model;
    TicTacToeView view;
    TicTacToeController controller(model, view);

    controller.startGame();
    return 0;
}