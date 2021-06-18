#include <vector>

using namespace std;

//class Solution {
//public:
//    int bit_count(int n) {
//        int count = 0;
//        while (n) {
//            if (n & 1) count++;
//            n >>= 1;
//        }
//        return count;
//    }
//
//    vector<int> countBits(int num) {
//        vector<int> res(num + 1);
//        if (!num) return res;
//        for (int i = 1; i <= num; i++) {
//            if (!res[i]) res[i] = bit_count(i);
//            for (int j = i * 2; j <= num; j *= 2)
//                res[j] = res[i];
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 1; i <= num; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};