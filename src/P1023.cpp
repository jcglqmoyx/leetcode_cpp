#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        int n = queries.size();
        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = check(queries[i], pattern);
        }
        return res;
    }

    bool check(string &query, string &pattern) {
        int m = query.length(), n = pattern.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            while (i < m && query[i] != pattern[j]) {
                if (isupper(query[i])) {
                    return false;
                }
                i++;
            }
            i++;
            j++;
        }
        if (i > m) return false;
        if (j < n) return false;
        while (i < m) {
            if (isupper(query[i++])) return false;
        }
        return true;
    }
};