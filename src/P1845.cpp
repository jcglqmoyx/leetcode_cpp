#include <queue>

using namespace std;

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<>> available, unavailable;

    SeatManager(int n) {
        for (int i = 1; i <= n; i++) available.push(i);
    }

    int reserve() {
        int t = available.top();
        if (!unavailable.empty() && t == unavailable.top()) {
            while (available.top() == unavailable.top()) {
                t = available.top();
                available.pop();
            }
            return t;
        } else {
            available.pop();
            return t;
        }
    }

    void unreserve(int seatNumber) {
        available.push(seatNumber);
    }
};