#include <deque>

using namespace std;

class HitCounter {
public:
    deque<int> hits;

    HitCounter() {
    }

    void hit(int timestamp) {
        hits.push_back(timestamp);
    }

    int getHits(int timestamp) {
        while (!hits.empty() && hits.front() + 300 <= timestamp) {
            hits.pop_front();
        }
        return hits.size();
    }
};