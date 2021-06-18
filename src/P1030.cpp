#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> cells(R * C, vector<int>(2));
        unordered_map<int, vector<vector<int>>> map;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int distance = get_distance(i, j, r0, c0);
                map[distance].push_back({i, j});
            }
        }
        for (int distance = 0, index = 0; distance <= 200; distance++) {
            if (map.count(distance)) {
                for (const vector<int> &point : map[distance]) {
                    cells[index++] = point;
                }
            }
        }
        return cells;
    }

    static int get_distance(int a, int b, int x, int y) {
        return abs(a - x) + abs(b - y);
    }
};