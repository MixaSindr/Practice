#include "model.h"

TicTacToeModel::TicTacToeModel()
    : board(3, std::vector<Player>(3, Player::None)),
    currentPlayer(Player::X),
    winner(Player::None),
    gameOver(false),
    playerXName("Player X"),
    playerOName("Player O"),
    playerXScore(0),
    playerOScore(0) {
}

void TicTacToeModel::resetGame() {
    board = std::vector<std::vector<Player>>(3, std::vector<Player>(3, Player::None));
    currentPlayer = Player::X;
    winner = Player::None;
    gameOver = false;
}

void TicTacToeModel::resetScore() {
    playerXScore = 0;
    playerOScore = 0;
    resetGame();
}

void TicTacToeModel::switchSides() {
    std::swap(playerXName, playerOName);
    std::swap(playerXScore, playerOScore);
    resetGame();
}

bool TicTacToeModel::makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 ||
        board[row][col] != Player::None || gameOver) {
        return false;
    }

    board[row][col] = currentPlayer;

    if (checkWin(currentPlayer)) {
        winner = currentPlayer;
        gameOver = true;
        if (winner == Player::X) playerXScore++;
        else playerOScore++;
    }
    else if ([this] {
        for (const auto& row : board) {
            for (Player cell : row) {
                if (cell == Player::None) return false;
            }
        }
        return true;
        }()) {
        gameOver = true;
    }
    else {
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
    }

    return true;
}

bool TicTacToeModel::isGameOver() const { return gameOver; }
bool TicTacToeModel::isDraw() const { return gameOver && winner == Player::None; }

// Геттеры
TicTacToeModel::Player TicTacToeModel::getCurrentPlayer() const { return currentPlayer; }
TicTacToeModel::Player TicTacToeModel::getCell(int row, int col) const { return board[row][col]; }
const std::string& TicTacToeModel::getPlayerXName() const { return playerXName; }
const std::string& TicTacToeModel::getPlayerOName() const { return playerOName; }
int TicTacToeModel::getPlayerXScore() const { return playerXScore; }
int TicTacToeModel::getPlayerOScore() const { return playerOScore; }
TicTacToeModel::Player TicTacToeModel::getWinner() const { return winner; }

// Сеттеры
void TicTacToeModel::setPlayerXName(const std::string& name) { playerXName = name; }
void TicTacToeModel::setPlayerOName(const std::string& name) { playerOName = name; }

// Приватные методы
bool TicTacToeModel::checkWin(Player player) const {
    // Проверка строк и столбцов
    for (int i = 0; i < 3; i++) {
        if (checkLine(i, 0, 0, 1, player) || // i-я строка
            checkLine(0, i, 1, 0, player)) {  // i-й столбец
            return true;
        }
    }

    // Проверка диагоналей
    return checkLine(0, 0, 1, 1, player) || // Главная диагональ
        checkLine(0, 2, 1, -1, player);  // Побочная диагональ
}

bool TicTacToeModel::checkLine(int startRow, int startCol, int dRow, int dCol, Player player) const {
    for (int i = 0; i < 3; i++) {
        if (board[startRow + i * dRow][startCol + i * dCol] != player) {
            return false;
        }
    }
    return true;
}