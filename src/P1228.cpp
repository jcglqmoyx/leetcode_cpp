#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    int missingNumber(vector<int> &arr) {
//        int n = arr.size();
//        if (n == 3) {
//            int diff1 = abs(arr[0] - arr[1]);
//            int diff2 = abs(arr[1] - arr[2]);
//            if (diff1 < diff2) {
//                return (arr[1] + arr[2]) / 2;
//            } else {
//                return (arr[0] + arr[1]) / 2;
//            }
//        }
//        unordered_map<int, int> map;
//        for (int i = 0; i < n - 1; i++) {
//            map[arr[i] - arr[i + 1]]++;
//        }
//        int most_frequent_diff = 0;
//        int count = 0;
//        for (const auto &x : map) {
//            if (x.second > count) {
//                most_frequent_diff = x.first;
//                count = x.second;
//            }
//        }
//        for (int i = 0; i < n - 1; i++) {
//            if (arr[i] - arr[i + 1] != most_frequent_diff) {
//                return (arr[i] + arr[i + 1]) / 2;
//            }
//        }
//        return 0;
//    }
//};

class Solution {
public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        int sum = 0, expected_sum = (arr.front() + arr.back()) * (n + 1) / 2;
        for (int num: arr) sum += num;
        return expected_sum - sum;
    }
};