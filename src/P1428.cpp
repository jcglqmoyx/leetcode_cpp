#include <vector>

using namespace std;

class BinaryMatrix {
public:
    int get(int row, int col);

    vector<int> dimensions();
};

#include <vector>

using namespace std;

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimension = binaryMatrix.dimensions();
        int rows = dimension[0], cols = dimension[1];
        int res = 1e9;
        for (int i = 0; i < rows; i++) {
            int col = 1e9;
            int l = 0, r = cols - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (binaryMatrix.get(i, mid)) {
                    col = mid;
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (binaryMatrix.get(i, l)) res = min(res, col);
        }
        return res == 1e9 ? -1 : res;
    }
};