class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            bool flag1 = true;
            bool flag2 = false;
            int num = i;
            while (num) {
                int digit = num % 10;
                if (digit == 3 || digit == 4 || digit == 7) {
                    flag1 = false;
                    break;
                } else if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    flag2 = true;
                }
                num /= 10;
            }
            if (flag1 && flag2) {
                count++;
            }
        }
        return count;
    }
};