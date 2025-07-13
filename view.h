#pragma once
#include "model.h"
#include <iostream>

class TicTacToeView {
public:
    void displayBoard(const TicTacToeModel& model) const;
    void displayScore(const TicTacToeModel& model) const;
    void displayCurrentPlayer(const TicTacToeModel& model) const;
    void displayGameOver(const TicTacToeModel& model) const;

    void getPlayerNames(std::string& playerX, std::string& playerO);
    void getPlayerMove(int& row, int& col);
    int showMenu();

    void showMessage(const std::string& message) const;
};