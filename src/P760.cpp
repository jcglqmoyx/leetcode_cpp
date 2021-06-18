#include <vector>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        int n = A.size();
        vector<int> res(n);
        int map[100001] = {0};
        for (int i = 0; i < n; i++) {
            map[B[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            res[i] = map[A[i]];
        }
        return res;
    }
};