#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
// LTE
//class Solution {
//public:
//    vector<int> mht;
//    unordered_map<int, vector<int>> neighbors;
//    int min_height = 20000;
//    int max_depth;
//
//    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
//        if (n == 1) return {0};
//        neighbors.reserve(n);
//        for (const vector<int> &edge : edges) {
//            neighbors[edge[0]].push_back(edge[1]);
//            neighbors[edge[1]].push_back(edge[0]);
//        }
//        for (int point = 0; point < n; point++) {
//            vector<bool> visited;
//            visited.resize(n, false);
//            max_depth = 0;
//            dfs(point, 0, visited);
//            if (max_depth < min_height) {
//                min_height = max_depth;
//                mht.clear();
//                mht.push_back(point);
//            } else if (max_depth == min_height) {
//                mht.push_back(point);
//            }
//        }
//        return mht;
//    }
//
//    void dfs(int point, int height, vector<bool> &visited) {
//        visited[point] = true;
//        max_depth = max(max_depth, height);
//        for (int neighbor : neighbors[point]) {
//            if (!visited[neighbor]) {
//                dfs(neighbor, height + 1, visited);
//            }
//        }
//    }
//};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};
        vector<int> degree(n);
        unordered_map<int, vector<int>> neighbors;
        for (const vector<int> &edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (n - q.size()) {
            int size = q.size();
            n -= size;
            while (size--) {
                int point = q.front();
                q.pop();
                degree[point]--;
                for (int neighbor : neighbors[point]) {
                    if (degree[neighbor] > 1) {
                        degree[neighbor]--;
                        if (degree[neighbor] == 1) {
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};