#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

struct Trie {
    int cnt;
    Trie *next[26];

    Trie() : cnt(0), next() {}

    void insert(string &s) {
        int n = s.length();
        Trie *root = this;
        for (int i = n - 1; ~i; i--) {
            if (!root->next[s[i] - 'a']) {
                root->next[s[i] - 'a'] = new Trie();
            }
            root = root->next[s[i] - 'a'];
            root->cnt++;
        }
    }

    bool query(string &s) {
        int n = s.length();
        Trie *root = this;
        for (int i = n - 1; ~i; i--) {
            root = root->next[s[i] - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (root->next[i]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string> &words) {
        Trie *trie = new Trie();
        unordered_set<string> word_set;
        for (string &w : words) {
            trie->insert(w);
            word_set.insert(w);
        }
        int res = 0;
        for (string w : word_set) {
            if (trie->query(w)) {
                res += (int) w.length() + 1;
            }
        }
        return res;
    }
};