class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        int half = 1 << (N - 2), total = 1 << (N - 1);
        if (N & 1) {
            if (K > half) {
                return kthGrammar(N - 1, total + 1 - K);
            } else {
                return kthGrammar(N - 1, K);
            }
        } else {
            if (K > half) {
                return 1 ^ kthGrammar(N - 1, total + 1 - K);
            } else {
                return kthGrammar(N - 1, K);
            }
        }
    }
};