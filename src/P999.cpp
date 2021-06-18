#include <vector>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>> &board) {
        int res = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R') {
                    int up = i - 1;
                    while (up > 0 && board[up][j] == '.') {
                        up--;
                    }
                    if (board[up][j] == 'p') {
                        res++;
                    }
                    int down = i + 1;
                    while (down < board.size() - 1 && board[down][j] == '.') {
                        down++;
                    }
                    if (board[down][j] == 'p') {
                        res++;
                    }
                    int left = j - 1;
                    while (left > 0 && board[i][left] == '.') {
                        left--;
                    }
                    if (board[i][left] == 'p') {
                        res++;
                    }
                    int right = j + 1;
                    while (right < board[0].size() - 1 && board[i][right] == '.') {
                        right++;
                    }
                    if (board[i][right] == 'p') {
                        res++;
                    }
                    return res;
                }
            }
        }
        return 0;
    }
};