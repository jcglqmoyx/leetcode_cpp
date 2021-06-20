#include <string>

using namespace std;

/*
class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int sh = stoi(startTime.substr(0, 2));
        int sm = stoi(startTime.substr(3, 2));
        int fh = stoi(finishTime.substr(0, 2));
        int fm = stoi(finishTime.substr(3, 2));
        int start = (sh * 60) + sm, finish = (fh * 60) + fm;
        int res = 0;
        if (start > finish) finish += 24 * 60;
        for (int i = start; i < finish; i++) {
            if (i % 15 == 0 && i + 15 <= finish) res++;
        }
        return res;
    }
};
*/

class Solution {
public:
    int get(string s) {
        int h, m;
        sscanf(s.c_str(), "%d:%d", &h, &m);
        return h * 60 + m;
    }

    int numberOfRounds(string startTime, string finishTime) {
        int x = get(startTime), y = get(finishTime);
        if (x > y) y += 24 * 60;
        return y / 15 - (x + 14) / 15;
    }
};