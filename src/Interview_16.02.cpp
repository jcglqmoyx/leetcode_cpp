#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class WordsFrequency {
public:
    unordered_map<string, int> map;

    WordsFrequency(vector<string> &book) {
        for (string &word : book) {
            map[word]++;
        }
    }

    int get(string word) {
        return map[word];
    }
};