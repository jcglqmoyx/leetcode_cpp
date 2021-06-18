#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string> &array) {
        queue<string> q;
        int count_digits = 0;
        int count_letters = 0;
        for (const string &str : array) {
            if (isdigit(str[0])) count_digits++;
            else count_letters++;
        }
        int mn = min(count_letters, count_digits);
        if (mn == 0) return {};
        for (const string &str : array) {
            if (isdigit(str[0])) count_digits++;
            else count_letters++;
            q.push(str);
            if (count_digits >= mn && count_letters >= mn) {
                break;
            }
        }
        while (count_digits != mn || count_letters != mn) {
            string front = q.front();
            if (isdigit(front[0])) count_digits--;
            else count_letters--;
            q.pop();
        }
        vector<string> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};