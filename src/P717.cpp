#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        if (bits.size() == 1) return true;
        int i = 0;
        while (i < bits.size() - 1) {
            if (bits[i]) i += 2;
            else i++;
        }
        return i == bits.size() - 1;
    }
};