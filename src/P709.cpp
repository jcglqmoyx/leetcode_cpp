#include <string>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        string res;
        for (char c : str) {
            res += tolower(c);
        }
        return res;
    }
};