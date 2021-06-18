#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        return (A + A).find(B) != std::string::npos;
    }
};