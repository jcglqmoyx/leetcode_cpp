#include <vector>

using namespace std;

//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>> &matrix, int target) {
//        int len = matrix.size(), wid = matrix[0].size();
//        for (int i = 0; i < len; i++) {
//            if (matrix[i][0] > target) break;
//            if (matrix[i].back() < target) continue;
//            int low = 0, high = wid - 1;
//            while (low <= high) {
//                int mid = low + (high - low) / 2;
//                if (matrix[i][mid] == target) return true;
//                else if (matrix[i][mid] > target) high = mid - 1;
//                else low = mid + 1;
//            }
//        }
//        return false;
//    }
//};

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int len = matrix.size(), wid = matrix[0].size();
        int i = len - 1, j = 0;
        while (i >= 0 && j < wid) {
            if (matrix[i][j] > target) i--;
            else if (matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};