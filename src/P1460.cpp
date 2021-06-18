#include <vector>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr) {
        int count[1001] = {0};
        for (int i = 0; i < target.size(); i++) {
            count[target[i]]++;
            count[arr[i]]--;
        }
        for (int i = 1; i <= 1000; i++) {
            if (count[i]) {
                return false;
            }
        }
        return true;
    }
};