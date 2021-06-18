#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool dfs(int i, int c, vector<vector<int>> &paths, vector<int> &color) {
        color[i] = c;
        for (int j : paths[i]) {
            if (!color[j]) {
                if (!dfs(j, 3 - c, paths, color)) {
                    return false;
                }
            } else if (color[j] == c) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        vector<vector<int>> paths(N + 1);
        vector<int> color(N + 1);
        for (auto &d : dislikes) {
            paths[d[0]].push_back(d[1]);
            paths[d[1]].push_back(d[0]);
        }
        bool flag = true;
        for (int i = 1; i <= N; i++) {
            if (!color[i]) {
                if (!dfs(i, 1, paths, color)) {
                    return false;
                }
            }
        }
        return flag;
    }
};