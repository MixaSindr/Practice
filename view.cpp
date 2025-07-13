#include "view.h"

void TicTacToeView::displayBoard(const TicTacToeModel& model) const {
    std::cout << "\n  0 1 2\n";
    for (int row = 0; row < 3; row++) {
        std::cout << row << " ";
        for (int col = 0; col < 3; col++) {
            switch (model.getCell(row, col)) {
            case TicTacToeModel::Player::X: std::cout << "X"; break;
            case TicTacToeModel::Player::O: std::cout << "O"; break;
            default: std::cout << "."; break;
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void TicTacToeView::displayScore(const TicTacToeModel& model) const {
    std::cout << "Score:\n";
    std::cout << model.getPlayerXName() << " (X): " << model.getPlayerXScore() << "\n";
    std::cout << model.getPlayerOName() << " (O): " << model.getPlayerOScore() << "\n\n";
}

void TicTacToeView::displayCurrentPlayer(const TicTacToeModel& model) const {
    std::string name = (model.getCurrentPlayer() == TicTacToeModel::Player::X) ?
        model.getPlayerXName() : model.getPlayerOName();
    std::cout << name << "'s turn ("
        << (model.getCurrentPlayer() == TicTacToeModel::Player::X ? "X" : "O")
        << ")\n";
}

void TicTacToeView::displayGameOver(const TicTacToeModel& model) const {
    if (model.isDraw()) {
        std::cout << "It's a draw!\n";
    }
    else {
        std::string winnerName = (model.getWinner() == TicTacToeModel::Player::X) ?
            model.getPlayerXName() : model.getPlayerOName();
        std::cout << winnerName << " wins!\n";
    }
}

void TicTacToeView::getPlayerNames(std::string& playerX, std::string& playerO) {
    std::cout << "Enter name for Player X: ";
    std::getline(std::cin, playerX);
    if (playerX.empty()) playerX = "Player X";

    std::cout << "Enter name for Player O: ";
    std::getline(std::cin, playerO);
    if (playerO.empty()) playerO = "Player O";
}

void TicTacToeView::getPlayerMove(int& row, int& col) {
    while (true) {
        std::cout << "Enter row and column (0-2): ";
        std::cin >> row >> col;

        if (std::cin.fail() || row < 0 || row > 2 || col < 0 || col > 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
        }
        else {
            std::cin.ignore();
            break;
        }
    }
}

int TicTacToeView::showMenu() {
    int choice;
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Play again\n";
        std::cout << "2. Change player names\n";
        std::cout << "3. Reset score\n";
        std::cout << "4. Switch sides\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";

        if (!(std::cin >> choice) || choice < 1 || choice > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please try again.\n";
        }
        else {
            std::cin.ignore();
            return choice;
        }
    }
}

void TicTacToeView::showMessage(const std::string& message) const {
    std::cout << message << "\n";
}