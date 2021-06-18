#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int start = i;
            int amount = gas[start];
            for (int count = 0; count < n; count++) {
                amount -= cost[(start + count) % n];
                if (amount < 0) {
                    break;
                }
                amount += gas[(start + count + 1) % n];
            }
            if (amount > 0) return start;
        }
        return -1;
    }
};