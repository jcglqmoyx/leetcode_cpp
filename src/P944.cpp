#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string> &A) {
        int deletion = 0;
        int len = (int) A.size(), wid = (int) A[0].size();
        for (int i = 0; i < wid; i++) {
            for (int j = 0; j < len - 1; j++) {
                if (A[j][i] > A[j + 1][i]) {
                    deletion++;
                    break;
                }
            }
        }
        return deletion;
    }
};