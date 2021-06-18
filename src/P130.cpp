//#include <vector>
//
//using namespace std;
//
//// DFS
//class Solution {
//public:
//    void solve(vector<vector<char>> &board) {
//        if (board.empty()) return;
//        int len = board.size(), wid = board[0].size();
//        for (int i = 0; i < len; i++) {
//            if (board[i][0] == 'O') dfs(board, i, 0);
//            if (board[i][wid - 1] == 'O') dfs(board, i, wid - 1);
//        }
//        for (int j = 0; j < wid; j++) {
//            if (board[0][j] == 'O') dfs(board, 0, j);
//            if (board[len - 1][j] == 'O') dfs(board, len - 1, j);
//        }
//
//        for (int i = 0; i < len; i++) {
//            for (int j = 0; j < wid; j++) {
//                if (board[i][j] == 'A') {
//                    board[i][j] = 'O';
//                } else if (board[i][j] == 'O') {
//                    board[i][j] = 'X';
//                }
//            }
//        }
//    }
//
//    void dfs(vector<vector<char>> &board, int i, int j) {
////        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] == 'X' || board[i][j] == 'A')
//        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] != 'O')
//            return;
//        board[i][j] = 'A';
//        dfs(board, i - 1, j);
//        dfs(board, i + 1, j);
//        dfs(board, i, j - 1);
//        dfs(board, i, j + 1);
//    }
//};




#include <queue>
#include <vector>

using namespace std;

// BFS
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) return;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        int len = board.size(), wid = board[0].size();
        for (int i = 0; i < len; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
            }
            if (board[i][wid - 1] == 'O') {
                q.push({i, wid - 1});
            }
        }
        for (int j = 0; j < wid; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
            }
            if (board[len - 1][j] == 'O') {
                q.push({len - 1, j});
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            board[x][y] = 'A';
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i];
                int my = y + dy[i];
                if (mx < 0 || mx == len || my < 0 || my == wid) continue;
                if (board[mx][my] == 'O') q.push({mx, my});
            }
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};