#include <vector>

using namespace std;

//class Solution {
//public:
//    int numWays(int n, vector<vector<int>> &relation, int k) {
//        K = k;
//        N = n;
//        dfs(relation, 0, 0);
//        return res;
//    }
//
//    void dfs(vector<vector<int>> &relations, int n, int k) {
//        if (k > K) return;
//        if (k == K && n == N - 1) {
//            res++;
//            return;
//        }
//        for (vector<int> &relation : relations) {
//            if (relation[0] == n) {
//                dfs(relations, relation[1], k + 1);
//            }
//        }
//    }
//
//private:
//    int res = 0;
//    int K;
//    int N;
//};

//class Solution {
//public:
//    int numWays(int n, vector<vector<int>> &relation, int k) {
//        vector<vector<int>> f(k + 1, vector<int>(n, 0));
//        f[0][0] = 1;
//        for (int i = 0; i < k; i++) {
//            for (auto &e : relation) {
//                int src = e[0], dst = e[1];
//                f[i + 1][dst] += f[i][src];
//            }
//        }
//        return f[k][n - 1];
//    }
//};

class Solution {
public:
    int numWays(int n, vector<vector<int>> &relation, int k) {
        vector<int> f(n);
        f[0] = 1;
        for (int i = 0; i < k; i++) {
            vector<int> next(n);
            for (auto &e : relation) {
                int src = e[0], dst = e[1];
                next[dst] += f[src];
            }
            f = next;
        }
        return f[n - 1];
    }
};