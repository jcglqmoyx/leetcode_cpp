#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> calls;

    RecentCounter() {
    }

    int ping(int t) {
        calls.push(t);
        while (t - calls.front() > 3000) {
            calls.pop();
        }
        return calls.size();
    }
};