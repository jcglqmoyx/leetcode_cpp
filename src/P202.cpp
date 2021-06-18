#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> occurred;
        while (n != 1) {
            int num = process(n);
            if (occurred.count(num)) {
                return false;
            }
            occurred.insert(num);
            n = num;
        }
        return true;
    }

    int process(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10) * (num % 10);
            num /= 10;
        }
        return sum;
    }
};