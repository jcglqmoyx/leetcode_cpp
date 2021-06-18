#include <vector>
#include <cmath>

using namespace std;

//class Solution {
//public:
//    bool judgeSquareSum(int c) {
//        vector<long> arr;
//        int square_root = sqrt( c);
//        for (long i = 0; i <= square_root; i++) {
//            arr.push_back(i * i);
//        }
//        int low = 0, high = (int) arr.size() - 1;
//        while (low <= high) {
//            long sum = arr[low] + arr[high];
//            if (sum == c) return true;
//            else if (sum < c) low++;
//            else high--;
//        }
//        return false;
//    }
//};

class Solution {
public:
    bool judgeSquareSum(int c) {
        long num = (long) c;
        for (long a = 0; a <= (long) sqrt(c); a++) {
            long b = c - a * a;
            long st = sqrt(b);
            if (st * st == b) return true;
        }
        return false;
    }
};