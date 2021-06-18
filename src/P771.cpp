#include <string>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        int map[128] = {0};
        for (char jewel : J) {
            map[jewel] = 1;
        }
        for (char stone : S) {
            if (map[stone]) {
                res++;
            }
        }
        return res;
    }
};