#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>> &shift) {
        for (int i = 0; i < shift.size(); i++) {
            int direction = shift[i][0];
            int distance = shift[i][1];
            if (direction != 0) {
                distance = s.length() - distance;
            }
            s = s.substr(distance) + s.substr(0, distance);
        }
        return s;
    }
};