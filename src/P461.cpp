class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming_distance = 0;
        for (int i = 0; i < 32; i++) {
            if ((x & 1) != (y & 1)) {
                hamming_distance++;
            }
            x >>= 1;
            y >>= 1;
        }
        return hamming_distance;
    }
};