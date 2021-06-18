#include "Employee.h"
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        int importance = 0;
        queue<Employee *> q;
        unordered_map<int, Employee *> m;
        for (Employee *employee : employees) {
            m[employee->id] = employee;
        }
        for (Employee *employee : employees) {
            if (employee->id == id) {
                q.push(employee);
                while (!q.empty()) {
                    for (int i = (int) q.size(); i > 0; i--) {
                        Employee *e = q.front();
                        q.pop();
                        importance += e->importance;
                        if (!e->subordinates.empty()) {
                            for (int subordinate : e->subordinates) {
                                q.push(m[subordinate]);
                            }
                        }
                    }
                }
                break;
            }
        }
        return importance;
    }
};