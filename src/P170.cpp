#include <vector>

using namespace std;

class TwoSum {
public:
    vector<int> arr;

    TwoSum() {
    }

    void add(int number) {
        arr.push_back(number);
    }

    bool find(int value) {
        sort(arr.begin(), arr.end());
        int low = 0, high = (int) arr.size() - 1;
        while (low < high) {
            int sum = arr[low] + arr[high];
            if (sum == value) return true;
            else if (sum < value) low++;
            else high--;
        }
        return false;
    }
};