#include <vector>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
        int map[101] = {0};
        for (int i = 0; i < pieces.size(); i++) {
            for (int j = 0; j < pieces[i].size(); j++) {
                map[pieces[i][j]] = i;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            int index = map[arr[i]];
            int m = 0;
            for (int n = 0; n < pieces[index].size(); n++) {
                if (arr[i + m] != pieces[index][n]) {
                    return false;
                }
                m++;
            }
            i += (int) pieces[index].size() - 1;
        }
        return true;
    }
};