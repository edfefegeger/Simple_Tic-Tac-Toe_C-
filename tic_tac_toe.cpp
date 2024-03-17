#include "tic_tac_toe.h"
#include <iostream>
using namespace std;

class Board {
private:
    char grid[3][3];

public:
    Board() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                grid[i][j] = '-';
            }
        }
    }

    void display() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << ' ' << grid[i][j] << ' ';
            }
            cout << endl;
        }
    }

    bool makeMove(int row, int col, char symbol) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || grid[row][col] != '-') {
            return false;
        }
        grid[row][col] = symbol;
        return true;
    }

    bool checkWin(char symbol) {
        
        for (int i = 0; i < 3; ++i) {
            if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) return true;
            if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol) return true;
        }

        
        if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) return true;
        if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) return true;

        return false;
    }
};

void TicTacToe::play() {
    Board board;
    int row, col;
    char currentPlayer = 'X';

    for (int i = 0; i < 9; ++i) {
        cout << "Текущее поле:" << endl;
        board.display();

        cout << "Игрок " << currentPlayer << ", введите ваш ход (строка и столбец): ";
        cin >> row >> col;

        if (!board.makeMove(row, col, currentPlayer)) {
            cout << "Неверный ход! Попробуйте снова." << endl;
            --i; 
            continue;
        }

        if (board.checkWin(currentPlayer)) {
            cout << "Игрок " << currentPlayer << " выигрывает!" << endl;
            return;
        }

        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Ничья!" << endl;
}
