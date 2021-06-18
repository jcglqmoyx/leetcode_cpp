#include <vector>
#include <stack>
#include <queue>

using namespace std;

//class Solution {
//public:
//    int countStudents(vector<int> &students, vector<int> &sandwiches) {
//        int circular = 0, square = 0;
//        for (int preference : students) {
//            circular += preference ^ 1;
//            square += preference ^ 0;
//        }
//        while (!sandwiches.empty()) {
//            if (students.front() == sandwiches.front()) {
//                circular -= sandwiches.front() ^ 1;
//                square -= sandwiches.front() ^ 0;
//                students.erase(students.begin());
//                sandwiches.erase(sandwiches.begin());
//            } else {
//                if (sandwiches.front() == 0 && circular == 0 || sandwiches.front() == 1 && square == 0) {
//                    return students.size();
//                } else {
//                    int preference = students.front();
//                    students.erase(students.begin());
//                    students.push_back(preference);
//                }
//            }
//        }
//        return 0;
//    }
//};

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        stack<int> S;
        queue<int> q;
        reverse(sandwiches.begin(), sandwiches.end());
        for (int x : sandwiches) S.push(x);
        for (int x : students) q.push(x);
        int s[2];
        s[0] = s[1] = 0;
        for (int x : students) s[x]++;
        while (!q.empty() && !S.empty() && s[S.top()] != 0) {
            if (q.front() != S.top()) {
                q.push(q.front());
                q.pop();
                continue;
            }
            s[q.front()]--;
            q.pop();
            S.pop();
        }
        return q.size();
    }
};