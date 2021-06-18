#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> large_group_positions;
        for (int i = 0; i < (int) s.length() - 2; i++) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
                int j = i + 2;
                while (j < s.length() && s[j] == s[j + 1]) {
                    j++;
                }
                large_group_positions.push_back({i, j});
                i = j;
            }
        }
        return large_group_positions;
    }
};