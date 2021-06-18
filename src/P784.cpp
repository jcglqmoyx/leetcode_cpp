#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> permutation;
        queue<string> q;
        q.push(S);
        for (int i = 0; i < S.length(); i++) {
            if (isalpha(S[i])) {
                for (int j = q.size(); j > 0; j--) {
                    string str = q.front();
                    q.pop();
                    q.push(str.substr(0, i) + ((char) toupper(S[i])) + S.substr(i + 1, S.length() - i - 1));
                    q.push(str.substr(0, i) + ((char) tolower(S[i])) + S.substr(i + 1, S.length() - i - 1));
                }
            }
        }
        while (!q.empty()) {
            permutation.push_back(q.front());
            q.pop();
        }
        return permutation;
    }
};