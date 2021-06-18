#include <vector>

using namespace std;

//class Solution {
//public:
//    int fixedPoint(vector<int> &A) {
//        for (int i = 0; i < A.size(); i++)
//            if (A[i] == i) return i;
//        return -1;
//    }
//};

class Solution {
public:
    int fixedPoint(vector<int> &A) {
        int n = A.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid > A[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return low < n && A[low] == low ? low : -1;
    }
};