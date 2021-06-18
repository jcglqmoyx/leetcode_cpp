#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
        vector<int> res(queries.size());
        int even_sum = 0;
        for (int num : A) {
            if ((num & 1) == 0) {
                even_sum += num;
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][1], val = queries[i][0];
            if (A[index] % 2 != 0 && val % 2 != 0) {
                even_sum += A[index] + val;
            } else if (A[index] % 2 == 0 && val % 2 == 0) {
                even_sum += val;
            } else if (A[index] % 2 == 0 && val % 2 != 0) {
                even_sum -= A[index];
            }
            res[i] = even_sum;
            A[index] += val;
        }
        return res;
    }
};