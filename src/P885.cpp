#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> positions;
        int total = R * C;
        positions.reserve(total);
        positions.push_back({r0, c0});
        int x = r0, y = c0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int direction = 0;
        int step = 1;
        int flag = 0;
        while (positions.size() < total) {
            for (int i = 0; i < step; i++) {
                int nx = x + dx[direction];
                int ny = y + dy[direction];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                    positions.push_back({nx, ny});
                    if (positions.size() == total) {
                        return positions;
                    }
                }
                x = nx;
                y = ny;
            }
            direction = (direction + 1) % 4;
            flag++;
            if (flag == 2) {
                step++;
                flag = 0;
            }
        }
        return positions;
    }
};