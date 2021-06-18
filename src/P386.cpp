//#include <vector>
//#include <string>
//
//using namespace std;
//
//class Solution {
//public:
//    static bool cmp(int a, int b) {
//        string m = to_string(a), n = to_string(b);
//        return m < n;
//    }
//
//    vector<int> lexicalOrder(int n) {
//        vector<int> arr(n);
//        for (int i = 0; i < n; i++) arr[i] = i + 1;
//        sort(arr.begin(), arr.end(), &cmp);
//        return arr;
//    }
//};



#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> ans;
//
//    vector<int> lexicalOrder(int n) {
//        ans.reserve(n);
//        for (int i = 1; i <= 9; i++) dfs(i, n);
//        return ans;
//    }
//
//    void dfs(int cur, int n) {
//        if (cur > n) return;
//        ans.push_back(cur);
//        for (int i = 0; i <= 9; i++) {
//            dfs(cur * 10 + i, n);
//        }
//    }
//};



class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = cur;
            if (cur * 10 <= n) cur *= 10;
            else {
                if (cur >= n) cur /= 10;
                cur += 1;
                while (cur % 10 == 0) cur /= 10;
            }
        }
        return res;
    }
};