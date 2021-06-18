#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string stack;
        for (char c : s) {
            stack.push_back(c);
            while (stack.size() >= 3 && stack.substr(stack.size() - 3) == "abc") {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};