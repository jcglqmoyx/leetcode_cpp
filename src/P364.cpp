#include <vector>

using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    int max_depth;
    int sum;

    int depthSumInverse(vector<NestedInteger> &nestedList) {
        max_depth = 0, sum = 0;
        for (NestedInteger &integer : nestedList) {
            calc_depth(integer, 1);
        }
        for (NestedInteger &integer : nestedList) {
            dfs(integer, max_depth);
        }
        return sum;
    }

    void calc_depth(NestedInteger &nested_integer, int depth) {
        if (nested_integer.isInteger()) {
            max_depth = max(max_depth, depth);
            return;
        }
        for (NestedInteger integer : nested_integer.getList()) {
            calc_depth(integer, depth + 1);
        }
    }

    void dfs(NestedInteger &nested_integer, int depth) {
        if (nested_integer.isInteger()) sum += nested_integer.getInteger() * depth;
        else {
            for (NestedInteger i : nested_integer.getList()) {
                dfs(i, depth - 1);
            }
        }
    }
};