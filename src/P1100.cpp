#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int n = S.length();
        if (n < K) return 0;
        unordered_map<char, int> map;
        for (int i = 0; i < K; i++) map[S[i]]++;
        int count = 0;
        if (map.size() == K) count++;
        for (int i = K; i < n; i++) {
            map[S[i]]++;
            map[S[i - K]]--;
            if (map[S[i - K]] == 0) map.erase(S[i - K]);
            if (map.size() == K) count++;
        }
        return count;
    }
};