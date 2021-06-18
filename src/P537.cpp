#include <string>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int index1 = a.find('+'), index2 = b.find('+');
        int real1 = stoi(a.substr(0, index1)), real2 = stoi(b.substr(0, index2));
        int imaginary1 = stoi(a.substr(index1 + 1, a.length() - index1 - 1)), imaginary2 = stoi(
                b.substr(index2 + 1, b.length() - index2 - 1));
        return to_string(real1 * real2 - imaginary1 * imaginary2) + '+' +
               to_string(real1 * imaginary2 + real2 * imaginary1) + 'i';
    }
};