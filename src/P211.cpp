#include <string>

using namespace std;

class Trie {
public:
    bool is_end;
    Trie *next[26];

    Trie() : is_end(false), next() {}

    void add_word(string &word) {
        Trie *node = this;
        for (char c : word) {
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }

    bool search(string &word, Trie *node, int start) {
        if (start == word.length()) return node->is_end;
        if (word[start] != '.') {
            if (!node->next[word[start] - 'a']) return false;
            node = node->next[word[start] - 'a'];
            return search(word, node, start + 1);
        } else {
            for (int i = 0; i < 26; i++) {
                if (node->next[i]) {
                    if (search(word, node->next[i], start + 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

class WordDictionary {
public:
    Trie *trie;

    WordDictionary() {
        trie = new Trie();
    }

    void addWord(string word) {
        trie->add_word(word);
    }

    bool search(string word) {
        return trie->search(word, trie, 0);
    }
};