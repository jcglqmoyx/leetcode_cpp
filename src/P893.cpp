#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string> &A) {
        unordered_set<string> set;
        for (const string &str : A) {
            set.insert(count(str));
        }
        return set.size();
    }

    string count(const string &str) {
        int count[52] = {0};
        for (int i = 0; i < str.length(); i++) {
            count[str[i] - 'a' + (i & 1) * 26]++;
        }
        string res;
        for (int i = 0; i < 52; i++) {
            res += to_string(count[i] + '_');
        }
        return res;
    }
};