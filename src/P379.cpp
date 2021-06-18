#include <vector>
#include <unordered_set>

using namespace std;

class PhoneDirectory {
public:
    unordered_set<int> checked;
    unordered_set<int> unchecked;

    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) unchecked.insert(i);
    }

    int get() {
        int res = -1;
        for (int number : unchecked) {
            res = number;
            checked.insert(number);
            unchecked.erase(number);
            break;
        }
        return res;
    }

    bool check(int number) {
        return unchecked.find(number) != unchecked.end();
    }

    void release(int number) {
        checked.erase(number);
        unchecked.insert(number);
    }
};