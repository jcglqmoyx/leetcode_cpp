#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int n, target;
    vector<int> used;

    bool dfs(vector<int> &arr, int index, int len, int cnt) {
        if (cnt == 3) return true;
        if (len == target) return dfs(arr, 0, 0, cnt + 1);
        for (int i = index; i < n; i++) {
            if (used[i]) continue;
            if (len + arr[i] <= target) {
                used[i] = true;
                if (dfs(arr, i + 1, len + arr[i], cnt)) return true;
                used[i] = false;
            }
            if (!len || len + arr[i] == target) return false;
            while (i + 1 < n && arr[i] == arr[i + 1]) i++;
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks) {
        if (matchsticks.empty()) return false;

        int sum = 0;
        for (int len : matchsticks) sum += len;
        if (sum % 4) return false;

        n = matchsticks.size();
        target = sum / 4;
        used.resize(n);

        sort(matchsticks.begin(), matchsticks.end(), greater<>());

        return dfs(matchsticks, 0, 0, 0);
    }
};