#include <stack>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> s;
    int index = 0;

    StockSpanner() {
    }

    int next(int price) {
        index++;
        while (!s.empty() && s.top().first <= price) s.pop();
        int res;
        if (!s.empty()) res = index - s.top().second;
        else res = index;
        s.push({price, index});
        return res;
    }
};