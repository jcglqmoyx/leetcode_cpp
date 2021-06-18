#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int> &arr, int k) {
        unordered_map<int, int> cnt;
        for (int num : arr) {
            int index = num % k;
            if (index < 0) {
                if (cnt[-index]) {
                    cnt[-index]--;
                } else if (cnt[-k - index]) {
                    cnt[-k - index]--;
                } else {
                    cnt[index]++;
                }
            } else {
                if (cnt[k - index]) {
                    cnt[k - index]--;
                } else if (cnt[-index]) {
                    cnt[-index]--;
                } else {
                    cnt[index]++;
                }
            }
        }
        for (auto[k, v] : cnt) {
            if (v) {
                if (k == 0 && v % 2 == 0) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};