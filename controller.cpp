#include "controller.h"

TicTacToeController::TicTacToeController(TicTacToeModel& model, TicTacToeView& view)
    : model(model), view(view) {
}

void TicTacToeController::startGame() {
    std::string playerX, playerO;
    view.getPlayerNames(playerX, playerO);
    model.setPlayerXName(playerX);
    model.setPlayerOName(playerO);

    while (true) {
        playRound();
        processMenu();
    }
}

void TicTacToeController::playRound() {
    model.resetGame();

    while (!model.isGameOver()) {
        view.displayScore(model);
        view.displayBoard(model);
        view.displayCurrentPlayer(model);

        int row, col;
        view.getPlayerMove(row, col);

        if (!model.makeMove(row, col)) {
            view.showMessage("Invalid move! Try again.");
        }
    }

    view.displayBoard(model);
    view.displayGameOver(model);
}

void TicTacToeController::processMenu() {
    while (true) {
        int choice = view.showMenu();

        switch (choice) {
        case 1: // Play again
            return;

        case 2: // Change names
        {
            std::string playerX, playerO;
            view.getPlayerNames(playerX, playerO);
            model.setPlayerXName(playerX);
            model.setPlayerOName(playerO);
            model.resetGame();
            return;
        }

        case 3: // Reset score
        
            model.resetScore();
            view.showMessage("Score has been reset");
            return;
        

        case 4: // Switch sides
            model.switchSides();
            view.showMessage("Sides switched");
            return;

        case 5: // Exit
            view.showMessage("Goodbye!");
            exit(0);
        }
    }
}