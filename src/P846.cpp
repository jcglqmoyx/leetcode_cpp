#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int W) {
        int n = hand.size();
        if (n % W) return false;
        unordered_map<int, int> cnt;
        for (int num : hand) cnt[num]++;
        sort(hand.begin(), hand.end());
        for (int num : hand) {
            if (cnt.find(num) == cnt.end()) continue;
            for (int i = num; i < num + W; i++) {
                if (cnt.find(i) == cnt.end()) return false;
                cnt[i]--;
                if (cnt[i] == 0) cnt.erase(i);
            }
        }
        return true;
    }
};