#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> paths;
    vector<int> path;
    vector<bool> st;

    int countArrangement(int n) {
        st.resize(n + 1);
        path.resize(n);
        dfs(0, n);
        return paths.size();
    }

    void dfs(int index, int n) {
        if (index == n) {
            paths.push_back(path);
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!st[i] && (((index + 1) % i == 0) || (i % (index + 1) == 0))) {
                st[i] = true;
                path[index] = i;
                dfs(index + 1, n);
                st[i] = false;
            }
        }
    }
};