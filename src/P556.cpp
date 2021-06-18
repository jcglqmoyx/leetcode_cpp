#include <string>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long res = stol(s);
        if (to_string(res).length() == s.length() && res < INT32_MAX && res > n) return (int) res;
        return -1;
    }
};