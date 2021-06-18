#include <vector>

using namespace std;

class Solution {
public:
    int n, m;

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        n = board.size(), m = board[0].size();
        dfs(board, x, y);
        return board;
    }

    bool is_valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(vector<vector<char>> &board, int i, int j) {
        if (!is_valid(i, j) || board[i][j] != 'E') return;
        char &c = board[i][j];
        int cnt = 0;
        for (int a = i - 1; a <= i + 1; a++) {
            for (int b = j - 1; b <= j + 1; b++) {
                if (is_valid(a, b) && board[a][b] == 'M') {
                    cnt++;
                }
            }
        }
        if (cnt) {
            c = (char) ('0' + cnt);
            return;
        }
        c = 'B';
        for (int a = i - 1; a <= i + 1; a++) {
            for (int b = j - 1; b <= j + 1; b++) {
                if (is_valid(a, b) && (a != i || b != j) && board[a][b] == 'M') {
                    dfs(board, a, b);
                }
            }
        }
    }
};