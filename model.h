#pragma once
#include <vector>
#include <string>

class TicTacToeModel {
public:
    enum class Player { None, X, O };

    TicTacToeModel();

    void resetGame();
    void resetScore();
    void switchSides();
    bool makeMove(int row, int col);
    bool isGameOver() const;
    bool isDraw() const;

    // Геттеры
    Player getCurrentPlayer() const;
    Player getCell(int row, int col) const;
    const std::string& getPlayerXName() const;
    const std::string& getPlayerOName() const;
    int getPlayerXScore() const;
    int getPlayerOScore() const;
    Player getWinner() const;

    // Сеттеры
    void setPlayerXName(const std::string& name);
    void setPlayerOName(const std::string& name);

private:
    bool checkWin(Player player) const;
    bool checkLine(int startRow, int startCol, int dRow, int dCol, Player player) const;

    std::vector<std::vector<Player>> board;
    Player currentPlayer;
    Player winner;
    bool gameOver;

    std::string playerXName;
    std::string playerOName;
    int playerXScore;
    int playerOScore;
};