class Solution {
public:
    int clumsy(int N) {
        int a[] = {1, 2, 6, 7};
        if (N <= 4) return a[N - 1];
        if (N % 4 == 0) return N + 1;
        if (N % 4 <= 2) return N + 2;
        return N - 1;
    }
};