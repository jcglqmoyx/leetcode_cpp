#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    string _b;
//    vector<int> ne;
//
//    void init() {
//        int n = _b.size();
//        ne.resize(n, -1);
//        for (int i = 1, j = -1; i < n; i++) {
//            while (j != -1 && _b[i] != _b[j + 1]) j = ne[j];
//            if (_b[i] == _b[j + 1]) j++;
//            ne[i] = j;
//        }
//    }
//
//    bool match(string &s) {
//        int m = s.length(), n = _b.length();
//        if (m < n) return false;
//        for (int i = 0, j = -1; i < m; i++) {
//            while (j != -1 && s[i] != _b[j + 1]) j = ne[j];
//            if (s[i] == _b[j + 1]) j++;
//            if (j == n - 1) return true;
//        }
//        return false;
//    }
//
//    int repeatedStringMatch(string a, string b) {
//        _b = b;
//        init();
//        if (match(a)) return 1;
//        string s = a;
//        int step = 1;
//        while (a.length() < b.length() * 2 || step <= 3) {
//            if (match(a)) return step;
//            a += s;
//            step++;
//        }
//        return -1;
//    }
//};

class Solution {
public:
    static const int N = 10010;
    int ne[N + 1];

    int repeatedStringMatch(string a, string b) {
        int n = b.size();
        int m = a.size();
        b = " " + b;
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && b[i] != b[j + 1]) j = ne[j];
            if (b[i] == b[j + 1]) j++;
            ne[i] = j;
        }
        int i = 0, j = 0;
        while (i - j < m) {
            while (j && b[j + 1] != a[i % m]) j = ne[j];
            if (a[i % m] == b[j + 1]) j++;
            i++;
            if (j == n) break;
        }
        if (j == n) {
            return (i % m == 0) ? i / m : i / m + 1;
        } else return -1;
    }
};