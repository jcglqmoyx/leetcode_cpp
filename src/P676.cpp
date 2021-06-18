#include <vector>
#include <string>
#include <cstring>

using namespace std;

//struct Trie {
//public:
//    Trie *next[26];
//    bool is_end;
//
//    void add(string &key) {
//        Trie *node = this;
//        for (char c : key) {
//            if (!node->next[c - 'a']) {
//                node->next[c - 'a'] = new Trie();
//            }
//            node = node->next[c - 'a'];
//        }
//        node->is_end = true;
//    }
//
//    bool query(string &key) {
//        return search(this, key, 0, false);
//    }
//
//    bool search(Trie *node, string &key, int index, int count) {
//        if (index == key.length()) return node->is_end && count == 1;
//        for (int i = 0; i < 26; i++) {
//            if (!node->next[i]) continue;
//            if (key[index] - 'a' == i) {
//                if (search(node->next[i], key, index + 1, count)) {
//                    return true;
//                }
//            } else if (search(node->next[i], key, index + 1, count + 1)) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    Trie() : next(), is_end(false) {}
//};
//
//class MagicDictionary {
//public:
//    Trie *trie;
//
//    MagicDictionary() {
//        trie = new Trie();
//    }
//
//    void buildDict(vector<string> dictionary) {
//        for (string &word : dictionary) trie->add(word);
//    }
//
//    bool search(string searchWord) {
//        return trie->query(searchWord);
//    }
//};

class Trie {
public:
    bool isEnd;
    Trie *next[26];

    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
};

class MagicDictionary {
public:
    Trie *root;

    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for (auto &w:dictionary) {
            Trie *node = root;
            for (auto &c:w) {
                if (!node->next[c - 'a'])
                    node->next[c - 'a'] = new Trie();
                node = node->next[c - 'a'];
            }
            node->isEnd = true;
        }
    }

    bool find(string &word, int index, bool used, Trie *node) {
        if (index == word.size())
            return node->isEnd && used;
        if (!node->next[word[index] - 'a']) {
            if (used)
                return false;
            else {
                for (int i = 0; i < 26; i++) {
                    if (node->next[i] && find(word, index + 1, true, node->next[i]))
                        return true;
                }
                return false;
            }
        } else {
            if (find(word, index + 1, used, node->next[word[index] - 'a']))
                return true;
            if (!used) {
                for (int i = 0; i < 26; i++) {
                    if (i != word[index] - 'a' && node->next[i] && find(word, index + 1, true, node->next[i]))
                        return true;
                }
                return false;
            }
        }
        return false;
    }

    bool search(string searchWord) {
        return find(searchWord, 0, false, root);
    }
};