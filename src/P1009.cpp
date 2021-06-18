class Solution {
public:
    int bitwiseComplement(int N) {
        int temp = 1;
        while (temp < N) {
            temp = (temp << 1) + 1;
        }
        return temp ^ N;
    }
};