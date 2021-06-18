#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        unordered_map<int, int> map;
        map[distance(p1, p2)]++;
        map[distance(p1, p3)]++;
        map[distance(p1, p4)]++;
        map[distance(p2, p3)]++;
        map[distance(p2, p4)]++;
        map[distance(p3, p4)]++;
        if (map.size() != 2) return false;
        for (auto &x : map) {
            if (x.first == 0 || x.second != 2 && x.second != 4) return false;
        }
        return true;
    }

    int distance(const vector<int> &p1, const vector<int> &p2) {
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        return x * x + y * y;
    }
};