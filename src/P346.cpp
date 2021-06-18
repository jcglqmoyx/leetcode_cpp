#include <queue>

using namespace std;

class MovingAverage {
public:
    queue<int> arr;
    int n;
    double sum;

    MovingAverage(int size) {
        n = size;
        sum = 0;
    }

    double next(int val) {
        sum += val;
        arr.push(val);
        if (arr.size() > n) {
            sum -= arr.front();
            arr.pop();
        }
        return sum / arr.size();
    }
};