#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isSafe(const vector<string>& board, int row, int col) {
    if (board[row][col] == '*') return 0;

    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return 0;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return 0;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == 'Q') return 0;
    }

    return 1;
}

int placeQueens(int row, vector<string>& board) {
    if (row == 8) return 1;

    int count = 0;

    for (int col = 0; col < 8; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';         
            count += placeQueens(row + 1, board);
            board[row][col] = '.';  
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    cout << placeQueens(0, board) << "\n";

    return 0;
}
