#include <vector>

using namespace std;

//class Solution {
//public:
//    int singleNumber(vector<int> &nums) {
//        int count[32] = {0};
//        for (int num : nums) {
//            for (int i = 0; i < 32; i++) {
//                count[i] += num & 1;
//                num >>= 1;
//            }
//        }
//        int single_number = 0;
//        for (int i = 0; i < 32; i++) {
//            if (count[i] % 3 != 0) {
//                single_number += 1 << i;
//            }
//        }
//        return single_number;
//    }
//};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int seen_once = 0, seen_twice = 0;
        for (int n : nums) {
            seen_once = ~seen_twice & (seen_once ^ n);
            seen_twice = ~seen_once & (seen_twice ^ n);
        }
        return seen_once;
    }
};