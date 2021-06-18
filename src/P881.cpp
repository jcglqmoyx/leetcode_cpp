#include <vector>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int cnt = 0, n = people.size(), l = 0, r = n - 1;
        while (l <= r) {
            int total = limit;
            int cur = 0;
            while (r >= l && people[r] <= total) {
                total -= people[r];
                r--;
                cur++;
                if (cur == 2) break;
            }
            while (l <= r && people[l] <= total) {
                if (cur == 2) break;
                total -= people[l];
                l++;
                cur++;
            }
            cnt++;
        }
        return cnt;
    }
};