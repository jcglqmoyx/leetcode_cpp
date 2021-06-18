#include <vector>

using namespace std;

//class Solution {
//public:
//    int smallestCommonElement(vector<vector<int>> &mat) {
//        int len = mat.size(), wid = mat[0].size();
//        for (int i = 0; i < wid; i++) {
//            bool flag = true;
//            for (int row = 1; row < len; row++) {
//                if (!binary_search(mat[row].begin(), mat[row].end(), mat[0][i])) {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag) return mat[0][i];
//        }
//        return -1;
//    }
//};

class Solution {
public:
    int smallestCommonElement(vector<vector<int>> &mat) {
        int len = mat.size(), wid = mat[0].size();
        vector<int> pos(len);
        for (int i = 0; i < wid; i++) {
            bool flag = true;
            for (int row = 1; row < len; row++) {
                pos[row] = lower_bound(begin(mat[row]) + pos[row], end(mat[row]), mat[0][i]) - begin(mat[row]);
                if (pos[row] >= wid) {
                    return false;
                }
                flag = mat[row][pos[row]] == mat[0][i];
                if (!flag) break;
            }
            if (flag) return mat[0][i];
        }
        return -1;
    }
};