#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>> &trust) {
        int people_who_are_trusted[1001] = {0};
        int people_who_trust_others[1001] = {0};
        for (const vector<int> &t : trust) {
            people_who_are_trusted[t[1]]++;
            people_who_trust_others[t[0]]++;
        }
        for (int i = 1; i <= 1000; i++) {
            if (people_who_are_trusted[i] == N - 1) {
                if (!people_who_trust_others[i]) {
                    return i;
                }
            }
        }
        return -1;
    }
};