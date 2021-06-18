#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

//class Solution {
//public:
//    vector<string> res;
//    unordered_set<string> set;
//
//    vector<string> generatePalindromes(string s) {
//        permute(s, 0);
//        return res;
//    }
//
//    void permute(string &s, int index) {
//        if (index == s.length()) {
//            if (is_palindrome(s) && set.find(s) == set.end()) {
//                res.push_back(s);
//                set.insert(s);
//            }
//            return;
//        }
//        for (int i = index; i < s.length(); i++) {
//            swap(s[i], s[index]);
//            permute(s, index + 1);
//            swap(s[i], s[index]);
//        }
//    }
//
//    bool is_palindrome(string &s) {
//        int n = s.length();
//        int low = 0, high = n - 1;
//        while (low < high) {
//            if (s[low] != s[high]) {
//                return false;
//            }
//            low++;
//            high--;
//        }
//        return true;
//    }
//};

class Solution {
public:
    unordered_set<string> set;

    vector<string> generatePalindromes(string s) {
        int map[26] = {0};
        for (char c : s) map[c - 'a']++;
        int count = 0;
        int ch = -1;
        for (int i = 0; i < 26; i++) {
            if (map[i] & 1) {
                ch = i;
                count++;
            }
        }
        if (count > 1) {
            return {};
        }
        s.clear();
        for (int i = 0; i < 26; i++) {
            if (map[i]) {
                for (int j = 0; j < map[i] / 2; j++) {
                    s.push_back('a' + i);
                }
            }
        }
        permute(s, 0, ch);
        vector<string> res;
        res.reserve(set.size());
        for (auto &str : set) res.push_back(str);
        return res;
    }

    void permute(string &s, int index, int ch) {
        if (index == s.length()) {
            string right = s;
            reverse(right.begin(), right.end());
            if (ch == -1) {
                set.insert(s + right);
            } else {
                string mid;
                mid.push_back('a' + ch);
                set.insert(s + mid + right);
            }
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (i > index && s[i] == s[index]) continue;
            swap(s[i], s[index]);
            permute(s, index + 1, ch);
            swap(s[i], s[index]);
        }
    }
};