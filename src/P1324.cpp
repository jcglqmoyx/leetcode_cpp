#include <vector>
#include <string>

using namespace std;

//class Solution {
//public:
//    vector<string> printVertically(string s) {
//        vector<string> words;
//        int max_len = 0;
//        for (int i = 0, j = 0; i < s.length(); i++) {
//            if (s[i] == ' ') {
//                words.push_back(s.substr(j, i - j));
//                max_len = max(max_len, i - j);
//                j = i + 1;
//            }
//            if (i == s.length() - 1) {
//                words.push_back(s.substr(j, i - j + 1));
//                max_len = max(max_len, i - j + 1);
//            }
//        }
//        vector<vector<char>> matrix(max_len, vector<char>(words.size()));
//        for (int i = 0; i < matrix.size(); i++) {
//            for (int j = 0; j < matrix[i].size(); j++) {
//                matrix[i][j] = i >= words[j].length() ? ' ' : words[j][i];
//            }
//        }
//        words.clear();
//        for (int i = 0; i < matrix.size(); i++) {
//            string word;
//            for (int j = 0; j < matrix[i].size(); j++) {
//                word.push_back(matrix[i][j]);
//            }
//            while (word.back() == ' ') word.pop_back();
//            words.push_back(word);
//        }
//        return words;
//    }
//};

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        int max_len = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                words.push_back(s.substr(j, i - j));
                max_len = max(max_len, i - j);
                j = i + 1;
            }
            if (i == s.length() - 1) {
                words.push_back(s.substr(j, i - j + 1));
                max_len = max(max_len, i - j + 1);
            }
        }
//        vector<vector<char>> matrix(max_len, vector<char>(words.size()));
//        for (int i = 0; i < matrix.size(); i++) {
//            for (int j = 0; j < matrix[i].size(); j++) {
//                matrix[i][j] = i >= words[j].length() ? ' ' : words[j][i];
//            }
//        }
        vector<string> res;
        for (int i = 0; i < max_len; i++) {
            string word;
            for (int j = 0; j < words.size(); j++) {
                char c = i >= words[j].length() ? ' ' : words[j][i];
                word.push_back(c);
            }
            while (word.back() == ' ') word.pop_back();
            res.push_back(word);
        }
        return res;
    }
};