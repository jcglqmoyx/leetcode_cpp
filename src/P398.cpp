#include <vector>

using namespace std;

class Solution {
public:
    vector<int> *p;

    Solution(vector<int> &nums) {
        p = &nums;
    }

    int pick(int target) {
        int count = 0;
        int random_index = 0;
        for (int i = 0; i < (*p).size(); i++) {
            if ((*p)[i] == target) {
                count++;
                if (rand() % count == count - 1) {
                    random_index = i;
                }
            }
        }
        return random_index;
    }
};