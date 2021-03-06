#include <string>

using namespace std;

class Solution {
public:
    string int2binary(int num) {
        string bin;
        while (num) {
            bin.push_back('0' + num % 2);
            num >>= 1;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }

    bool queryString(string S, int N) {
        for (int i = (N >> 1) + 1; i <= N; i++) {
            if (S.find(int2binary(i)) == string::npos) return false;
        }
        return true;
    }
};