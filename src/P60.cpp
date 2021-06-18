#include <string>

using namespace std;

//class Solution {
//public:
//    string getPermutation(int n, int k) {
//        string s(n, '0');
//        for (int i = 0; i < n; i++) {
//            s[i] = i + '0' + 1;
//        }
//        for (int i = 0; i < k - 1; i++) {
//            next_permutation(s.begin(), s.end());
//        }
//        return s;
//    }
//};

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact[9] = {1, 1};
        for (int i = 2; i < 9; i++) fact[i] = fact[i - 1] * i;
        bool st[10] = {false};
        string res;
        for (int i = 0; i < n; i++) {
            int f = fact[n - i - 1];
            for (int j = 1; j <= n; j++) {
                if (!st[j]) {
                    if (f < k) k -= f;
                    else {
                        res += to_string(j);
                        st[j] = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};