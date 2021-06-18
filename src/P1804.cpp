#include <string>

using namespace std;

class Trie {
public:
    Trie *next[26];
    int count_start_with;
    int count_is_end;

    Trie() {
        count_start_with = 0;
        count_is_end = 0;
        for (auto &i : next) {
            i = nullptr;
        }
    }

    void insert(string word) {
        Trie *node = this;
        for (char c : word) {
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
            node->count_start_with++;
        }
        node->count_is_end++;
    }

    int countWordsEqualTo(string word) {
        Trie *node = this;
        for (char c : word) {
            if (!node->next[c - 'a']) return 0;
            node = node->next[c - 'a'];
        }
        return node->count_is_end;
    }

    int countWordsStartingWith(string prefix) {
        Trie *node = this;
        for (char c : prefix) {
            if (!node->next[c - 'a']) return 0;
            node = node->next[c - 'a'];
        }
        return node->count_start_with;
    }

    void erase(string word) {
        Trie *node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            node->count_start_with--;
        }
        node->count_is_end--;
    }
};