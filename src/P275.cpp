#include <vector>

using namespace std;

//class Solution {
//public:
//    int hIndex(vector<int> &citations) {
//        int h_index = 0, n = citations.size();
//        for (int i = n - 1; i >= 0; i--) {
//            if (citations[i] > n - i - 1) {
//                h_index++;
//            } else {
//                break;
//            }
//        }
//        return h_index;
//    }
//};

class Solution {
public:
    int hIndex(vector<int> &citations) {
        if (citations.empty()) return 0;
        int n = citations.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (citations[mid] == n - mid) {
                return n - mid;
            } else if (citations[mid] > n - mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return n - low;
    }
};