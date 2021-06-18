#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
public:
    bool isInteger() const;

    int getInteger() const;

    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
            st.push(*iter);
        }
    }

    int next() {
        auto t = st.top();
        st.pop();
        return t.getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            auto cur = st.top();
            if (cur.isInteger()) return true;
            st.pop();
            auto list = cur.getList();
            for (auto iter = list.rbegin(); iter != list.rend(); iter++) {
                st.push(*iter);
            }
        }
        return false;
    }
};