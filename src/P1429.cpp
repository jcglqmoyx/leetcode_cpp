#include <vector>
#include <unordered_map>

using namespace std;

class FirstUnique {
public:
    unordered_map<int, int> map;
    vector<int> arr;
    int ptr = 0;

    FirstUnique(vector<int> &nums) {
        arr = nums;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
    }

    int showFirstUnique() {
        while (ptr < arr.size() && map[arr[ptr]] > 1) ptr++;
        return ptr < arr.size() ? arr[ptr] : -1;
    }

    void add(int value) {
        arr.push_back(value);
        map[value]++;
    }
};