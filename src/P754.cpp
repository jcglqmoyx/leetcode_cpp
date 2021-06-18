class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = 0, sum = 0;
        for (; sum < target || (sum - target) & 1; n++, sum += n);
        return n;
    }
};